#include "update_record.h"
#include "ui_update_record.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QTabWidget>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QDateTimeEdit>
update_record::update_record(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::update_record)
{
    ui->setupUi(this);
    if(!QSqlDatabase::contains("update_recordName")){
        db3=QSqlDatabase::addDatabase("QODBC","update_recordName");
        db3.setDatabaseName("MySQLDSN");
        if(!db3.open()){
            QMessageBox::information(this,"infor","连接数据库失败");
            qDebug()<<"err"<<db3.lastError().text();
        }
        else{
            db3=QSqlDatabase::database("update_recordName");
        }
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->setAlternatingRowColors(true);
        QSqlQuery query("SHOW TABLES",db3);
        while (query.next()) {
            QString tableName=query.value(0).toString ();
            ui->comboBox->addItem(tableName);
        }
        connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&update_record::on_comboBox_currentIndexChanged);
    }
}

update_record::~update_record()
{
    delete ui;
}

void update_record::loadData()
{
    QString tableName = ui->comboBox->currentText();
    QSqlQuery query(db3);
    query.prepare(QString("SELECT * FROM %1").arg(tableName));
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数
    if (!db3.isOpen()) {
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

void update_record::on_comboBox_currentIndexChanged(int index)
{
    QString tableName=ui->comboBox->itemText(index);
    loadData();
}
