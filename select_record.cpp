#include "select_record.h"
#include "ui_select_record.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>
#include<QSqlRecord>
#include <QDateTime>
#include<QVariant>
#include "qsqlquery.h"
#include<QDateTimeEdit>
#include<QTableView>
select_record::select_record(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::select_record)
{
    ui->setupUi(this);
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db7 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db7.setDatabaseName("MySQLDSN");
        if (!db7.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db7.lastError().text();
        }
    } else {
        db7 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);

    QSqlQuery query("SHOW TABLES", db7);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }

    connect(ui->select,&QPushButton::clicked,this,&select_record::on_selectButtonClicke);
    connect(ui->exit,&QPushButton::clicked,this,&select_record::on_exitButtonClicke);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &select_record::on_comboBox_currentIndexChanged);
}

select_record::~select_record()
{
    delete ui;
}
void select_record::on_comboBox_currentIndexChanged(int index)
{

    QString tableName = ui->comboBox->itemText(index);

    ui->comboBox2->clear();

    QSqlQuery query(db7); // 确保查询对象使用正确的数据库连接
    query.prepare("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = :tableName");
    query.bindValue(":tableName", tableName);
    if (query.exec()) {
        while (query.next()) {
            QString columnName = query.value(0).toString();
            ui->comboBox2->addItem(columnName);
        }
    } else {
        QMessageBox::critical(this, "错误", "获取列信息失败：" + query.lastError().text());
    }
    //loadData();
}

void select_record::on_exitButtonClicke()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}

// void select_record::loadData()
// {
//     QString tableName = ui->comboBox->currentText();
//     QSqlQuery query(db7);
//     query.prepare(QString("SELECT * FROM %1").arg(tableName));
//     ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
//     ui->tableWidget->setRowCount(0); // 清空行数
//     if (!db7.isOpen()) {
//         QMessageBox::information(this, "Error", "数据库未打开！");
//         qDebug() << "Database is not open!";
//         return;
//     }
//     if (query.exec()) {
//         QSqlRecord record = query.record();
//         QStringList header;
//         header << "序号";
//         for (int col = 0; col < record.count(); col++) {
//             header << record.fieldName(col);
//         }
//         ui->tableWidget->setColumnCount(header.size());
//         ui->tableWidget->setHorizontalHeaderLabels(header);

//         int rowCount = 0;
//         while (query.next()) {
//             ui->tableWidget->insertRow(rowCount);
//             QTableWidgetItem *item = new QTableWidgetItem(QString::number(rowCount + 1)); // 添加序号
//             ui->tableWidget->setItem(rowCount, 0, item);
//             for (int col = 0; col < query.record().count(); col++) {
//                 QVariant value = query.value(col);
//                 QString itemText;
//                 if (value.metaType().id() == QMetaType::QDateTime) {
//                     QDateTime dateTime = value.toDateTime();
//                     itemText = dateTime.toString("yyyy年MM月dd日Thh时mm分ss秒");
//                 } else {
//                     itemText = value.toString();
//                 }
//                 QTableWidgetItem *item = new QTableWidgetItem(itemText);
//                 ui->tableWidget->setItem(rowCount, col + 1, item); // 从第二列开始填充数据
//             }
//             rowCount++;
//         }
//     } else {
//         QMessageBox::information(this, "Error", "无法查询表数据: " + query.lastError().text());
//         qDebug() << "Error retrieving table data:" << query.lastError().text();
//     }
// }

void select_record::on_selectButtonClicke()
{
    QString tableName = ui->comboBox->currentText();
    QString columnName = ui->comboBox2->currentText();
    QString searchCondition = ui->lineEdit->text().trimmed(); // 获取并去除首尾空格

    if (searchCondition.isEmpty()) {
        QMessageBox::information(this, "提示", "请输入查询条件！");
        return;
    }

    QSqlQuery query(db7);
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数

    if (!db7.isOpen()) {
        QMessageBox::information(this, "Error", "数据库未打开！");
        qDebug() << "Database is not open!";
        return;
    }

    // 构建 SQL 查询语句，使用指定的列进行 LIKE 模糊匹配
    QString sql = QString("SELECT * FROM %1 WHERE %2 = %3").arg(tableName).arg(columnName).arg(searchCondition);

    query.prepare(sql);

    if (query.exec()) {
        QSqlRecord record = query.record();
        QStringList header;
        header << "序号";
        for (int col = 0; col < record.count(); ++col) {
            header << record.fieldName(col);
        }
        ui->tableWidget->setColumnCount(header.size());
        ui->tableWidget->setHorizontalHeaderLabels(header);

        int rowCount = 0;
        while (query.next()) {
            ui->tableWidget->insertRow(rowCount);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(rowCount + 1)); // 添加序号
            ui->tableWidget->setItem(rowCount, 0, item);
            for (int col = 0; col < record.count(); ++col) {
                QVariant value = query.value(col);
                QString itemText;
                if (value.metaType().id() == QMetaType::QDateTime) {
                    QDateTime dateTime = value.toDateTime();
                    itemText = dateTime.toString("yyyy年MM月dd日Thh时mm分ss秒");
                } else {
                    itemText = value.toString();
                }
                QTableWidgetItem *item = new QTableWidgetItem(itemText);
                ui->tableWidget->setItem(rowCount, col + 1, item); // 从第二列开始填充数据
            }
            rowCount++;
        }
    } else {
        QMessageBox::information(this, "Error", "无法查询表数据: " + query.lastError().text());
        qDebug() << "Error retrieving table data:" << query.lastError().text();
    }

}
