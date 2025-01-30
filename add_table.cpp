#include "add_table.h"
#include "ui_add_table.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDateTime>
#include <QVariant>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableView>
#include <QComboBox>
add_table::add_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_table)
{
    ui->setupUi(this);
    // 检查数据库连接是否已经存在
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db8 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db8.setDatabaseName("MySQLDSN");
        if (!db8.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db8.lastError().text();
        }
    } else {
        db8 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QStringList headers;
    headers << "列名" << "类型" << "主键";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 添加列类型下拉框
    QStringList types;
    types << "整数" << "小数" << "字符串" << "时间" << "日期";
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QComboBox *comboBox = new QComboBox();
        comboBox->addItems(types);
        ui->tableWidget->setCellWidget(i, 1, comboBox);

        QCheckBox *checkBox = new QCheckBox();
        checkBox->setStyleSheet("QCheckBox::indicator { width: 20px; height: 20px; }"); // 可选：调整勾选框大小
        ui->tableWidget->setCellWidget(i, 2, checkBox);
    }
    connect(ui->add, &QPushButton::clicked, this, &add_table::addRow);
     connect(ui->delete_2, &QPushButton::clicked, [this]() {
         int nCount = ui->tableWidget->rowCount();
         if (nCount > 1) {
             ui->tableWidget->removeRow(nCount - 1);


         }
     });
     connect(ui->add_table_clear, &QPushButton::clicked, this, &add_table::clearAll);
      connect(ui->add_table_ok, &QPushButton::clicked, this, &add_table::createTable);
}

add_table::~add_table()
{
    if (db8.isOpen()) {
        db8.close();
    }
    delete ui;
}
void add_table::addRow()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // 添加列类型下拉框
    QStringList types;
    types << "整数" << "小数" << "字符串" << "时间" << "日期";
    QComboBox *comboBox = new QComboBox();
    comboBox->addItems(types);
    ui->tableWidget->setCellWidget(row, 1, comboBox);

    QCheckBox *checkBox = new QCheckBox();
    checkBox->setStyleSheet("QCheckBox::indicator { width: 20px; height: 20px; }"); // 可选：调整勾选框大小
    ui->tableWidget->setCellWidget(row, 2, checkBox);
}
void add_table::createTable()
{
    QString tableName = ui->newtable_name->text();
    if (tableName.isEmpty()) {
        QMessageBox::warning(this, "警告", "表名不能为空！");
        return;
    }

    // 检查表名是否重复
    QSqlQuery query(db8);
    if (!query.exec(QString("SHOW TABLES LIKE '%1'").arg(tableName))) {
        QMessageBox::warning(this, "警告", "查询表名失败！");
        return;
    }
    if (query.next()) {
        QMessageBox::warning(this, "警告", "表名已存在！");
        return;
    }

    // 构建创建表的SQL语句
    QString createTableSQL = QString("CREATE TABLE %1 (").arg(tableName);

    QStringList primaryKeyColumns; // 用于存储主键列名

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        if (!item || item->text().isEmpty()) {
            QMessageBox::warning(this, "警告", "列名不能为空！");
            return;
        }
        QString columnName = item->text();

        QComboBox *comboBox = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(i, 1));
        if (!comboBox) {
            QMessageBox::warning(this, "警告", "类型选择框不存在！");
            return;
        }
        QString columnType = comboBox->currentText();
        QString sqlType;
        if (columnType == "整数") {
            sqlType = "INT";
        } else if (columnType == "小数") {
            sqlType = "DECIMAL(10, 2)"; // 可以根据需要调整精度
        } else if (columnType == "字符串") {
            sqlType = "VARCHAR(255)";
        } else if (columnType == "时间") {
            sqlType = "TIME";
        } else if (columnType == "日期") {
            sqlType = "DATE";
        }

        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i, 2));
        if (!checkBox) {
            QMessageBox::warning(this, "警告", "主键勾选框不存在！");
            return;
        }

        createTableSQL += QString("%1 %2").arg(columnName).arg(sqlType);

        if (checkBox->isChecked()) {
            if (!primaryKeyColumns.isEmpty()) {
                QMessageBox::warning(this, "警告", "只能选择一个主键！");
                return;
            }
            primaryKeyColumns.append(columnName);
        }

        if (i < ui->tableWidget->rowCount() - 1) {
            createTableSQL += ", ";
        }
    }

    // 添加主键定义
    if (!primaryKeyColumns.isEmpty()) {
        createTableSQL += ", PRIMARY KEY (" + primaryKeyColumns.join(", ") + ")";
    }

    createTableSQL += ")";


    // 执行创建表的SQL语句
    if (query.exec(createTableSQL)) {
        QMessageBox::information(this, "信息", "表创建成功！");
    } else {
        QMessageBox::warning(this, "警告", "表创建失败！");
        qDebug() << "error create table because" << query.lastError().text();
    }
}
void add_table::clearAll()
{
    ui->newtable_name->clear();
    ui->tableWidget->setRowCount(0);

}

void add_table::exit()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}
