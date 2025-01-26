#include "lessen_storage.h"
#include "ui_lessen_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableWidgetItem>
#include <QSqlTableModel>
lessen_storage::lessen_storage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lessen_storage)
{
    ui->setupUi(this);
    if(!QSqlDatabase::contains("add_storageConnectionName")){
        db5 = QSqlDatabase::addDatabase("QODBC", "add_storageConnectionName");
        db5.setDatabaseName("MySQLDSN");
        if(!db5.open()){
            QMessageBox::information(this, "info", "连接数据库失败");
            qDebug() << "error open database because" << db5.lastError().text();
        }
    } else {
        db5 = QSqlDatabase::database("add_storageConnectionName");
    }
    QSqlQuery query("SHOW TABLES", db5);
    while(query.next()){
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    connect(ui->lessen_exit,&QPushButton::clicked,this,&lessen_storage::on_lessen_storage_exit_clicked);
    connect(ui->lessen_ok,&QPushButton::clicked,this,&lessen_storage::on_lessen_storage_clicked);
}

lessen_storage::~lessen_storage()
{
    delete ui;
}

void lessen_storage::on_lessen_storage_clicked(bool checked)
{
    if (!db5.isOpen()) {
        QMessageBox::information(this, "Error", "数据库连接已关闭");
        return;
    }

    // 获取 QLineEdit 的文本
    QString productName = ui->lineEdit->text();  // 产品名称
    QString quantityStr = ui->lineEdit_2->text();  // 出库数量

    int number;
    if (!validatePositiveInteger(quantityStr, number)) {
        QMessageBox::information(this, "Error", "请输入有效的正整数作为入库数量");
        return;
    }

    // 查询数据库以检查是否存在该产品
    QSqlQuery query(db5);
    query.prepare("SELECT id, number FROM inv_table WHERE name = :name");
    query.bindValue(":name", productName);

    if (query.exec() && query.next()) {
        // 找到产品
        int productId = query.value(0).toInt();
        int currentNumber = query.value(1).toInt();
        if (number > currentNumber) {
            QMessageBox::information(this, "Error",
                                     QString("出库数量有误：当前库存为 %1，不能出库超过库存的数量").arg(currentNumber));
            return;
        }

        // 更新库存数量
        int newNumber = currentNumber - number;
        QDateTime currentDateTime = QDateTime::currentDateTime();

        // 更新数据库中的数量
        QSqlQuery updateQuery(db5);
        updateQuery.prepare("UPDATE inv_table SET number = :newNumber, out_time = :out_time WHERE id = :id");
        updateQuery.bindValue(":newNumber", newNumber);
        updateQuery.bindValue(":out_time", currentDateTime.toString("yyyy-MM-dd hh:mm:ss"));
        updateQuery.bindValue(":id", productId);
        if (updateQuery.exec()) {
            qDebug() << "Updated inventory for product ID:" << productId;
            QMessageBox::information(this, "提示", "入库成功！");
        } else {
            qDebug() << "Error updating database:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Error", "更新库存失败，请重试");
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

bool lessen_storage::validatePositiveInteger(const QString &input, int &output)
{
    bool isValid;
    output = input.toInt(&isValid);
    return isValid && output > 0;
}

void lessen_storage::on_lessen_storage_exit_clicked(bool checked)
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}
