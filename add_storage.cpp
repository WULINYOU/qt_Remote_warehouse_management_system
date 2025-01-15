#include "add_storage.h"
#include "ui_add_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableWidgetItem>

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


    // 连接 Storage_newok 按钮的点击事件
    connect(ui->Storage_newok, &QPushButton::clicked, this, &add_Storage::on_Storage_new_ok_clicked);
}

add_Storage::~add_Storage()
{
    delete ui;
}

void add_Storage::on_Storage_new_ok_clicked()
{
    // 获取用户输入的数据
    QString productName = ui->lineEdit->text();
    int quantity = ui->lineEdit_2->text().toInt();
    QString storageType = ui->comboBox_2->currentText();
    QDateTime storageTime = ui->lineEdit_3->dateTime();
    QString storagePerson = ui->lineEdit_5->text();
    double price = ui->lineEdit_4->text().toDouble();

    // 获取选中的表名
    QString tableName = ui->comboBox->currentText();

    // 获取当前表中最大的ID值
    QSqlQuery query(db4);
    query.prepare(QString("SELECT MAX(id) FROM %1").arg(tableName));
    if (query.exec() && query.next()) {
        int lastId = query.value(0).toInt();
        int newId = lastId + 1;

        // 插入数据到数据库
        query.prepare(QString("INSERT INTO %1 (id, productName, quantity, storageType, storageTime, storagePerson, price, out_time) VALUES (:id, :productName, :quantity, :storageType, :storageTime, :storagePerson, :price, :out_time)").arg(tableName));
        query.bindValue(":id", newId);
        query.bindValue(":productName", productName);
        query.bindValue(":quantity", quantity);
        query.bindValue(":storageType", storageType);
        query.bindValue(":storageTime", storageTime);
        query.bindValue(":storagePerson", storagePerson);
        query.bindValue(":price", price);
        query.bindValue(":out_time", QVariant(QVariant::String)); // 出库时间插入为空

        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Failed to insert data: " + query.lastError().text());
        } else {
            QMessageBox::information(this, "Success", "Data inserted successfully!");
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to get last ID: " + query.lastError().text());
    }
}


