﻿#include "ui_update_record.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QTabWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDateTimeEdit>
#include <QTableView>
#include "update_record.h"
#include <QSqlDatabase>

update_record::update_record(QWidget *parent, const QString &comment)
    : QDialog(parent)
    , ui(new Ui::update_record)
    , m_journal (new journal(this))
    , m_comment(comment)
{

    ui->setupUi(this);
    QString connectionName = "update_recordName"; // 使用唯一的连接名称
    if (!QSqlDatabase::contains(connectionName)) {
        db3 = QSqlDatabase::addDatabase("QODBC", connectionName);
        db3.setDatabaseName("MySQLDSN");
        if (!db3.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败");
            qDebug() << "err" << db3.lastError().text();
        }
    } else {
        db3 = QSqlDatabase::database(connectionName);
    }

    QSqlQuery query("SHOW TABLES", db3);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &update_record::on_comboBox_currentIndexChanged);
    connect(ui->update_button, &QPushButton::clicked, this, &update_record::on_updateButtonClicked);
    connect(ui->exit_button, &QPushButton::clicked, this, &update_record::exitButtonClicked);
    if (!db3.isOpen()) {
        QMessageBox::information(this, "Error", "数据库未打开！");
        qDebug() << "Database is not open!";
        return;
    }

    ui->type_show->addItem("      ");
    ui->type_show->addItem("成品库存");
    ui->type_show->addItem("退货库存");
    ui->type_show->addItem("季节性库存");

    // ui->type_show->hide(); // 初始化时隐藏 type_show 下拉框
    // ui->newword->hide();  // 初始化时隐藏 newword 输入框
}

update_record::~update_record() {
      delete ui;
}

void update_record::on_updateButtonClicked() {
    QString tableName = ui->comboBox->currentText();
    QString columnName = ui->table_element->currentText();
    QString name = ui->name->text();
    QString newValue = ui->newword->text();
    QString comment = m_comment;
    qDebug() << "Comment value:" << comment;
    QSqlQuery query(db3); // 确保查询对象使用正确的数据库连接
    QString sql = QString("UPDATE %1 SET %2 = :newValue WHERE name = :name").arg(tableName).arg(columnName);
    query.prepare(sql);
    query.bindValue(":newValue", newValue);
    query.bindValue(":name", name);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "数据更新成功！");
        m_journal->logAction(comment, "数据更新成功！");
        QString logMessage = QString("数据更新成功：表 %1，列 %2，名称 %3，新值 %4")
                                 .arg(tableName).arg(columnName).arg(name).arg(newValue);
        m_journal->logAction(comment, logMessage);
        qDebug() << "Log action called with comment:" << comment << "and action: 插入成功"; // 添加调试输出

    } else {
        QMessageBox::critical(this, "错误", "数据更新失败：" + query.lastError().text());
        m_journal->logAction(comment, "数据更新失败");
    }
}

void update_record::exitButtonClicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "返回", "确定要返回管理页面?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->close();
    }
}

void update_record::on_comboBox_currentIndexChanged(int index) {
    QString tableName = ui->comboBox->itemText(index);

    ui->table_element->clear();

    QSqlQuery query(db3); // 确保查询对象使用正确的数据库连接
    query.prepare("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = :tableName");
    query.bindValue(":tableName", tableName);
    if (query.exec()) {
        while (query.next()) {
            QString columnName = query.value(0).toString();
            ui->table_element->addItem(columnName);
        }
    } else {
        QMessageBox::critical(this, "错误", "获取列信息失败：" + query.lastError().text());
    }
}
