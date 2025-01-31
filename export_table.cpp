#include "export_table.h"
#include "ui_export_table.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>
#include<QSqlRecord>
#include <QDateTime>
#include<QVariant>
#include <qfile.h>
#include <qdir.h>
#include "qsqlquery.h"
#include<QTableView>
//#include <QXlsx/Document.h>
export_table::export_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::export_table)
{
    ui->setupUi(this);
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db10 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db10.setDatabaseName("MySQLDSN");
        if (!db10.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db10.lastError().text();
        }
    } else {
        db10 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QSqlQuery query("SHOW TABLES", db10);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->tablename->addItem(tableName);
    }

    // 连接信号和槽
    connect(ui->tablename, &QComboBox::currentIndexChanged, this, &export_table::on_comboBox_currentIndexChanged);

}

void export_table::on_comboBox_currentIndexChanged(int index) {
    qDebug() << "ComboBox changed to index:" << index;
    QString tableName = ui->tablename->currentText();
    qDebug() << "Selected table name:" << tableName;

    QSqlQuery query(db10);
    query.prepare(QString("SELECT * FROM %1").arg(tableName));
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数

    if (!db10.isOpen()) {
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

// void export_table::onexport_okButtonClicke()
// {
//     QString fileName = QFileDialog::getSaveFileName(this,
//                                                     tr("Save File"), "",
//                                                     tr("Text Files (*.txt);;Excel Files (*.xlsx)"));

//     if (fileName.isEmpty())
//         return;

//     if (fileName.endsWith(".txt")) {
//         QFile file(fileName);
//         if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//             QMessageBox::warning(this, tr("Save File"),
//                                  tr("Cannot write file %1:\n%2.")
//                                      .arg(QDir::toNativeSeparators(fileName),
//                                           file.errorString()));
//             return;
//         }

//         QTextStream out(&file);
//         // 写入表头
//         for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
//             out << ui->tableWidget->horizontalHeaderItem(col)->text();
//             if (col < ui->tableWidget->columnCount() - 1) {
//                 out << "\t";
//             }
//         }
//         out << "\n";

//         // 写入数据
//         for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
//             for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
//                 out << ui->tableWidget->item(row, col)->text();
//                 if (col < ui->tableWidget->columnCount() - 1) {
//                     out << "\t";
//                 }
//             }
//             out << "\n";
//         }
//     } else if (fileName.endsWith(".xlsx")) {
//         QXlsx::Document xlsx;
//         // 写入表头
//         for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
//             xlsx.write(1, col + 1, ui->tableWidget->horizontalHeaderItem(col)->text());
//         }

//         // 写入数据
//         for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
//             for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
//                 xlsx.write(row + 2, col + 1, ui->tableWidget->item(row, col)->text());
//             }
//         }

//         if (!xlsx.saveAs(fileName)) {
//             QMessageBox::warning(this, tr("Save File"),
//                                  tr("Cannot write file %1:\n%2.")
//                                      .arg(QDir::toNativeSeparators(fileName),
//                                           "Failed to save Excel file"));
//             return;
//         }
//     }
// }


export_table::~export_table()
{
    if (db10.isOpen()) {
        db10.close();
    }
    delete ui;
}
