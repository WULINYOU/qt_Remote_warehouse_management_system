#include "delete_record.h"
#include "ui_delete_record.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>
#include<QSqlRecord>
#include <QDateTime>
#include<QVariant>
#include<QDateTimeEdit>
#include<QTableView>
#include "qsqlquery.h"
#include <QTimer>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include"journal.h"
#include "ConfirmDeleteDialog.h"
delete_record::delete_record(QWidget *parent, const QString &comment)
    : QDialog(parent)
    , ui(new Ui::delete_record)
    , m_journal (new journal(this))
    , m_comment(comment)
{
    ui->setupUi(this);
    if (!QSqlDatabase::contains("delete_recordConnectionName")) {
        db6 = QSqlDatabase::addDatabase("QODBC", "delete_recordConnectionName");
        db6.setDatabaseName("MySQLDSN");
        if (!db6.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db6.lastError().text();
        }
    } else {
        db6 = QSqlDatabase::database("delete_recordConnectionName");
    }


    QSqlQuery query("SHOW TABLES", db6);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    connect(ui->first_sure,&QPushButton::clicked,this,&delete_record::onfirst_sureButtonClicke);
     connect(ui->exit,&QPushButton::clicked,this,&delete_record::onexitButtonClicke);
}

delete_record::~delete_record()
{
    delete ui;
}

void delete_record::onfirst_sureButtonClicke()
{
    QString name = ui->name->text();
    QString again_name = ui->agagin_name->text();
     QString comment = m_comment;
    qDebug() << "Comment value:" << comment;
    if (name != again_name) {
        QMessageBox::warning(this, "两次产品名称不兼容", "请确认产品名称");
        return;
    }

    // 弹出确认删除对话框
    ConfirmDeleteDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // 用户点击了确定
        QString tableName = ui->comboBox->currentText();

        // 确保数据库连接有效
        if (!db6.isOpen()) {
            db6.open();
        }

        QSqlQuery query(db6);
        QString insertQuery = QString("DELETE FROM %1 WHERE name = :name").arg(tableName);
        query.prepare(insertQuery);
        query.bindValue(":name", name);
        QString logMessage = QString("删除记录：表 %1，名称 %2")
                                 .arg(tableName).arg(name);
        if (query.exec()) {
            m_journal->logAction(comment, "成功删除");
            m_journal->logAction(comment, logMessage);
            QString successMessage = QString("成功删除 %1").arg(name);
            QMessageBox::information(this, "提示", successMessage);
        } else {
            QString errorMessage = query.lastError().text();
            QMessageBox::critical(this, "错误", errorMessage);
            m_journal->logAction(comment, "删除错误");
        }
    } else {
        // 用户点击了取消
        QMessageBox::information(this, "提示", "删除操作已取消");
    }

    // 重新启用确定按钮
    ui->first_sure->setEnabled(true);
}
void delete_record::onexitButtonClicke()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}
