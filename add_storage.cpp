#include "add_storage.h"
#include "ui_add_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableWidgetItem>
#include <QSqlTableModel>
#include"journal.h"
add_Storage::add_Storage(QWidget *parent, const QString &comment)
    : QDialog(parent)
    , ui(new Ui::add_Storage)
    , m_journal (new journal(this))
    , m_comment(comment)
{
    ui->setupUi(this);
    if(!QSqlDatabase::contains("add_storageConnectionName")){
        db4 = QSqlDatabase::addDatabase("QODBC", "add_storageConnectionName");
        db4.setDatabaseName("MySQLDSN");
        if(!db4.open()){
            QMessageBox::information(this, "info", "连接数据库失败");
            qDebug() << "error open database because" << db4.lastError().text();
        }
    } else {
        db4 = QSqlDatabase::database("add_storageConnectionName");
    }
    QSqlQuery query("SHOW TABLES", db4);
    while(query.next()){
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }

}

add_Storage::~add_Storage()
{
    delete ui;
}

bool add_Storage::validatePositiveInteger(const QString &input, int &output) {
    bool isValid;
    output = input.toInt(&isValid);
    return isValid && output > 0;
}

void add_Storage::on_Storage_exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}

void add_Storage::on_Storage_oldok_clicked()
{
    if (!db4.isOpen()) {
        QMessageBox::information(this, "Error", "数据库连接已关闭");
        return;
    }

    // 获取 QLineEdit 的文本
    QString productName = ui->lineEdit->text();  // 产品名称
    QString quantityStr = ui->lineEdit_2->text();  // 入库数量

    int number;
    if (!validatePositiveInteger(quantityStr, number)) {
        QMessageBox::information(this, "Error", "请输入有效的正整数作为入库数量");
        return;
    }

    // 查询数据库以检查是否存在该产品
    QSqlQuery query(db4);
    query.prepare("SELECT id, number FROM inv_table WHERE name = :name");
    query.bindValue(":name", productName);

    if (query.exec() && query.next()) {
        // 找到产品
        int productId = query.value(0).toInt();
        int currentNumber = query.value(1).toInt();

        // 更新库存数量
        int newNumber = currentNumber + number;
     QDateTime currentDateTime = QDateTime::currentDateTime();
        QString comment = m_comment;
        // 更新数据库中的数量
        QSqlQuery updateQuery(db4);
     updateQuery.prepare("UPDATE inv_table SET number = :newNumber, in_time = :in_time WHERE id = :id");
     updateQuery.bindValue(":newNumber", newNumber);
     updateQuery.bindValue(":in_time", currentDateTime.toString("yyyy-MM-dd hh:mm:ss"));
     updateQuery.bindValue(":id", productId);
        if (updateQuery.exec()) {
            QString logMessage = QString("入库记录：表 inv_table，名称 %1，数量 %2")
                                     .arg(productName).arg(quantityStr);
            qDebug() << "Updated inventory for product ID:" << productId;
            QMessageBox::information(this, "提示", "入库成功！");
            m_journal->logAction(comment, "入库成功！");
            m_journal->logAction(comment, logMessage);

        } else {
            qDebug() << "Error updating database:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Error", "更新库存失败，请重试");
            m_journal->logAction(comment, "更新库存失败，请重试"+ updateQuery.lastError().text());
        }
    } else {
        // 未找到产品
        if (query.lastError().isValid()) {
            qDebug() << "Error checking database:" << query.lastError().text();
        }
        QMessageBox::information(this, "Error", "未找到该产品，请检查产品名称");
    }
    query.finish();
}




