#include "add_record.h"
#include "ui_add_record.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QMessageBox>
#include<QSqlRecord>
#include <QDateTime>
#include<QVariant>
#include "qsqlquery.h"
#include"manage.h"
add_record::add_record(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_record)
    , timer(new QTimer(this))
{
    ui->setupUi(this);
    // 检查数据库连接是否已经存在
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db2 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db2.setDatabaseName("MySQLDSN");
        if (!db2.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db2.lastError().text();
        }
    } else {
        db2 = QSqlDatabase::database("manageUniqueConnectionName");
    }
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);

    QSqlQuery query("SHOW TABLES", db2);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }

    connect(ui->add, &QPushButton::clicked, [this]() {
        qDebug() << "Add button clicked";
        QTableWidgetItem *item[10];
        int nCount = ui->tableWidget->rowCount();
        if (nCount < 10) {
            ui->tableWidget->insertRow(nCount);
            item[0] = new QTableWidgetItem(QString::number(nCount + 1)); // 添加序号
            ui->tableWidget->setItem(nCount, 0, item[0]);
        }
        for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
            if (ui->tableWidget->horizontalHeaderItem(col)->text() == "type") {
                QComboBox *comboBox = new QComboBox();
                comboBox->addItem("      ");
                comboBox->addItem("成品库存");
                comboBox->addItem("退货库存");
                comboBox->addItem("季节性库存");
                ui->tableWidget->setCellWidget(nCount, col, comboBox);
            }
        }
    });
    connect(ui->reduce, &QPushButton::clicked, [this]() {
        qDebug() << "Reduce button clicked";
        int nCount = ui->tableWidget->rowCount();
        if (nCount > 1) {
            ui->tableWidget->removeRow(nCount - 1);
            // 更新序号列
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(row + 1)); // 修正序号更新逻辑
                ui->tableWidget->setItem(row, 0, item);
            }
        }
    });
    connect(ui->add_exit,&QPushButton::clicked,this,&add_record::on_backmanage);
    connect(timer, &QTimer::timeout, this, &add_record::updateShowTimeLabel);
    timer->start(1000);
}

add_record::~add_record()
{
    delete ui;
}

void add_record::on_comboBox_currentIndexChanged(int index)
{
    QString tableName = ui->comboBox->itemText(index);
    QSqlQuery query(db2);
    query.prepare(QString("SELECT * FROM %1").arg(tableName));
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数
    if (!db2.isOpen()) {
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

    }
}

void add_record::on_backmanage()
{

    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?",
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }


}

void add_record::updateShowTimeLabel()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedTime = currentDateTime.toString("系统时间：yyyy年MM月dd日hh时mm分ss秒");
    ui->showtime_label->setText(formattedTime);
}
