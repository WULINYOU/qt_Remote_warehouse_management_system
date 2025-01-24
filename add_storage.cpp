#include "add_storage.h"
#include "ui_add_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableWidgetItem>
#include <QSqlTableModel>

add_Storage::add_Storage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_Storage)
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
    ui->comboBox_2->addItem("      ");
    ui->comboBox_2->addItem("成品库存");
    ui->comboBox_2->addItem("退货库存");
    ui->comboBox_2->addItem("季节性库存");

    // 设置 lineEdit_3 为 QDateTimeEdit
    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
    dateTimeEdit->setCalendarPopup(true);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->verticalLayout_2->replaceWidget(ui->lineEdit_3, dateTimeEdit);
    ui->lineEdit_3->deleteLater();
    ui->lineEdit_3 = dateTimeEdit;


   // connect(ui->Storage_oldok,&QPushButton::clicked,this,&add_Storage::on_Storage_oldok_clicked);

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


void add_Storage::on_Storage_oldok_clicked(bool checked)
{
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

        // 更新数据库中的数量
        QSqlQuery updateQuery(db4);
        updateQuery.prepare("UPDATE inv_table SET number = :newNumber WHERE id = :id");
        updateQuery.bindValue(":newNumber", newNumber);
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
}
void add_Storage::on_Storage_newok_clicked(bool checked)
{

    // 获取 QLineEdit 的文本
    QString productName = ui->lineEdit->text();  // 产品名称
    QString quantityStr = ui->lineEdit_2->text();  // 入库数量
    int number;
    if (!validatePositiveInteger(quantityStr, number)) {
        QMessageBox::information(this, "Error", "请输入有效的正整数作为入库数量");
        return;
    }
    QSqlQuery query(db4);
    query.prepare("SELECT id, number FROM inv_table WHERE name = :name");
    query.bindValue(":name", productName);

    if (query.exec() && query.next()) {
      QMessageBox::information(this, "Error", "找到该产品，请检查产品名称");
    } else {
        // 未找到产品
        if (query.lastError().isValid()) {
            qDebug() << "Error checking database:" << query.lastError().text();
        }
        QMessageBox::information(this, "Error", "未找到该产品，请检查产品名称");
    }
}
