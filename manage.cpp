#include "manage.h"
#include "ui_manage.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QFontMetrics>
#include"add_record.h"
manage::manage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::manage)
{
    ui->setupUi(this);

    // 检查数据库连接是否已经存在
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db1 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db1.setDatabaseName("MySQLDSN");
        if (!db1.open()) {
            QMessageBox::information(this, "infor", "连接数据库失败！");
            qDebug() << "error open database because" << db1.lastError().text();
        }
    } else {
        db1 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QSqlQuery query("SHOW TABLES", db1);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }

    // 连接 comboBox 的 currentIndexChanged 信号到槽函数
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &manage::on_comboBox_currentIndexChanged);
    connect(ui->manage_Exit,&QPushButton::clicked,this,&manage::onExitButtonClicke);
    connect(ui->add_record,&QPushButton::clicked,this,&manage::onaddrecordButtonClicke);
}

manage::~manage()
{
    delete ui;
    if (db1.isOpen()) {
        db1.close();  // 关闭数据库连接
    }

    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
}

void manage::loadData()
{
    QString tableName = ui->comboBox->currentText();
    QSqlQuery query(db1);
    query.prepare(QString("SELECT * FROM %1").arg(tableName));
    ui->tableWidget->clearContents(); // 清空 tableWidget 的内容
    ui->tableWidget->setRowCount(0); // 清空行数
    if (!db1.isOpen()) {
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
        adjustColumnWidths();
    } else {
        QMessageBox::information(this, "Error", "无法查询表数据: " + query.lastError().text());
        qDebug() << "Error retrieving table data:" << query.lastError().text();
    }
}

void manage::onaddrecordButtonClicke()
{
    add_record *add_recordDialog=new add_record;
    add_recordDialog->show();
}


void manage::on_comboBox_currentIndexChanged(int index)
{
    QString tableName = ui->comboBox->itemText(index);
    loadData(); // 调用 loadData 方法加载所选表的数据
}

void manage::adjustColumnWidths()
{
    QFontMetrics fm(ui->tableWidget->font());
    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        int maxWidth = 0;
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                QString text = item->text();
                int width = fm.horizontalAdvance(text);
                if (width > maxWidth) {
                    maxWidth = width;
                }
            }
        }
        ui->tableWidget->setColumnWidth(col, maxWidth + 50); // 设置列宽
    }
}

void manage::onExitButtonClicke()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "退出", "确定要退出吗？",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

