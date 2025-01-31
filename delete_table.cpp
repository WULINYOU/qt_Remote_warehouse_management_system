#include "delete_table.h"
#include "ui_delete_table.h"
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
#include "ConfirmDeleteDialog.h"
delete_table::delete_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_table)
{
    ui->setupUi(this);
    if (!QSqlDatabase::contains("manageUniqueConnectionName1")) {
        db9 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName1");
        db9.setDatabaseName("MySQLDSN");
        if (!db9.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db9.lastError().text();
        }
    } else {
        db9 = QSqlDatabase::database("manageUniqueConnectionName1");
    }

   ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QSqlQuery query("SHOW TABLES", db9);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    connect(ui->delete_table_ok,&QPushButton::clicked,this,&delete_table::on_deleta_table_ButtonClicke);
}

delete_table::~delete_table()
{
    if (db9.isOpen()) {
        db9.close();  // 关闭数据库连接
    }
    delete ui;
}
void delete_table::on_comboBox_currentIndexChanged(int index) {
    QString tableName = ui->comboBox->currentText();
    QSqlQuery query(db9);
    query.prepare(QString("SELECT * FROM %1").arg(tableName));
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数
    if (!db9.isOpen()) {
        QMessageBox::information(this, "Error", "数据库未打开！");
        qDebug() << "Database is not open!";
        return;
    }
    if (query.exec()) {
        QSqlRecord record = query.record();
        QStringList header;
        header << "序号";
        for (int col = 0; col < record.count(); col++) {
            header << record.fieldName(col);
        }
        ui->tableWidget->setColumnCount(header.size());
        ui->tableWidget->setHorizontalHeaderLabels(header);

        int rowCount = 0;
        while (query.next()) {
            ui->tableWidget->insertRow(rowCount);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(rowCount + 1)); // 添加序号
            ui->tableWidget->setItem(rowCount, 0, item);
            for (int col = 0; col < query.record().count(); col++) {
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
void delete_table::on_deleta_table_ButtonClicke()
{
    ConfirmDeleteDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString tableName = ui->comboBox->currentText();
        QSqlQuery query(db9);
        if (!query.exec(QString("SHOW TABLES LIKE '%1'").arg(tableName))) {
            QMessageBox::warning(this, "警告", "查询表名失败！");
            return;
        }
        if (!query.next()) {
            QMessageBox::warning(this, "警告", "表名不存在！");
            return;
        }
        QString dropTableSQL = QString("DROP TABLE %1").arg(tableName); // 修正 SQL 语句
        if (query.exec(dropTableSQL)) {
            QMessageBox::information(this, "信息", "表删除成功！");
        } else {
            QMessageBox::warning(this, "警告", "表删除失败！");
            qDebug() << "error dropping table because" << query.lastError().text();
        }
    } else {
        // 用户点击了取消
        QMessageBox::information(this, "提示", "删除操作已取消");
    }

    // 重新启用确定按钮
    ui->delete_table_ok->setEnabled(true);
}
