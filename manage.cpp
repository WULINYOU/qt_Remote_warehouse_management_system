#include "manage.h"
#include "ui_manage.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QFontMetrics>
#include<QDateTimeEdit>
#include<QTableView>
#include "add_record.h"
#include"update_record.h"
#include"add_storage.h"
#include"lessen_storage.h"
#include"delete_record.h"
#include"select_record.h"
#include"add_table.h"
#include"delete_table.h"
#include"select_table.h"
#include"journal.h"

manage::manage(QWidget *parent, const QString &comment)
    : QDialog(parent)
    , ui(new Ui::manage)
    , timer(new QTimer(this))
    , m_comment(comment)
{
    ui->setupUi(this);

    // 检查数据库连接是否已经存在
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db1 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db1.setDatabaseName("MySQLDSN");
        if (!db1.open()) {
            // QMessageBox::information(this, "infor", "连接数据库失败！");
            // qDebug() << "error open database because" << db1.lastError().text();
        }
    } else {
        db1 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QSqlQuery query("SHOW TABLES", db1);
    while (query.next()) {

        QString tableName = query.value(0).toString();
        if (this->m_comment != "管理员" && (tableName == "inventory.login" || tableName == "inventory.invite_code")) {
            continue;
        }
        ui->comboBox->addItem(tableName);
    }


    // 连接 comboBox 的 currentIndexChanged 信号到槽函数
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &manage::on_comboBox_currentIndexChanged);
    connect(ui->manage_Exit,&QPushButton::clicked,this,&manage::onExitButtonClicke);
    connect(ui->add_record,&QPushButton::clicked,this,&manage::onaddrecordButtonClicke);
    connect(ui->refresh,&QPushButton::clicked,this,&manage::onrefreshButtonClicke);
    connect(ui->update_record,&QPushButton::clicked,this,&manage::onupdatButtonclicke);
    connect(ui->Storage,&QPushButton::clicked,this,&manage::onStorageButtonClicke);
    connect(ui->lessen,&QPushButton::clicked,this,&manage::onlessenButtonClicke);
    connect(ui->delete_record,&QPushButton::clicked,this,&manage::ondeleteButtonClicke);
    connect(ui->select_record,&QPushButton::clicked,this,&manage::onselectButtonClicke);
    connect(ui->add_table,&QPushButton::clicked,this,&manage::onaddButtonClicke);
    connect(ui->delete_table,&QPushButton::clicked,this,&manage::ondeleteTableButtonClicke);
    connect(ui->select_table,&QPushButton::clicked,this,&manage::onselecttableButtonClikce);
    connect(ui->journal,&QPushButton::clicked,this,&manage::onlogButtonClickee);
    //time_label
    connect(timer, &QTimer::timeout, this, &manage::updateShowTimeLabel);
    timer->start(500);
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

    // 检查数据库连接是否打开
    if (!db1.isOpen()) {
        if (!db1.open()) {
            return;
        }
    }

    // 检查是否为管理员，如果不是管理员则不允许访问某些表
    QStringList hiddenTables = {"inventory.login", "inventory.invite_code"};
    if (m_comment != "管理员" && hiddenTables.contains(tableName)) {
        QMessageBox::information(this, "提示", "您没有权限访问该表！");
        return;
    }

    // 准备查询
    query.prepare(QString("SELECT * FROM %1").arg(tableName));

    // 清空 tableWidget 的内容
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // 执行查询
    if (query.exec()) {
        QSqlRecord record = query.record();
        QStringList header;
        header << "序号";
        for (int col = 0; col < record.count(); col++) {
            header << record.fieldName(col);
        }
        ui->tableWidget->setColumnCount(header.size());
        ui->tableWidget->setHorizontalHeaderLabels(header);

        // 填充数据
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
        // QMessageBox::information(this, "Error", "无法查询表数据: " + query.lastError().text());
        // qDebug() << "Error retrieving table data:" << query.lastError().text();
    }
}

void manage::onaddrecordButtonClicke()
{
    add_record *add_recordDialog=new add_record(this,m_comment);
    add_recordDialog->show();
}


void manage::onrefreshButtonClicke()
{
    // 关闭当前的数据库连接
    if (db1.isOpen()) {
        db1.close();
    }

    // 移除当前的数据库连接
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");

    // 重新创建并打开数据库连接
    db1 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
    db1.setDatabaseName("MySQLDSN");
    if (!db1.open()) {
        QMessageBox::information(this, "提示", "连接数据库失败！");
        qDebug() << "连接数据库失败：" << db1.lastError().text();
        return;
    }

    ui->comboBox->clear();

    // 重新查询数据库中的表名并填充到 comboBox 中
    QSqlQuery query("SHOW TABLES", db1);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        if (this->m_comment != "管理员" && (tableName == "inventory.login" || tableName == "inventory.invite_code")) {
            continue;
        }
        ui->comboBox->addItem(tableName);
    }

    // 重新加载当前选中表的数据
    loadData();
}


void manage::updateShowTimeLabel()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedTime = currentDateTime.toString("系统时间：yyyy年MM月dd日hh时mm分ss秒");
    ui->time_label->setText(formattedTime);
}

void manage::onupdatButtonclicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    if (db1.isOpen()) {
        db1.close();
    }
    update_record *updateDialog=new update_record(this,m_comment);
    updateDialog->show();
}

void manage::onStorageButtonClicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    add_Storage *add_StorageDialog=new add_Storage;
    add_StorageDialog->show();
}

void manage::ondeleteButtonClicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    if (db1.isOpen()) {
        db1.close();
    }
    delete_record *delete_recordDialog= new delete_record(this,m_comment);
    delete_recordDialog->show();
}

void manage::onselectButtonClicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    if (db1.isOpen()) {
        db1.close();
    }
    select_record *select_recordDialog=new select_record(this,m_comment);
    select_recordDialog->show();
}

void manage::ondeleteTableButtonClicke()
{

    QSqlDatabase::removeDatabase("manageUniqueConnectionName");

    delete_table *delete_tableDialog=new delete_table;
    delete_tableDialog->show();
}

void manage::onlessenButtonClicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    lessen_storage *lessen_storageDialog=new lessen_storage;
    lessen_storageDialog->show();
}

void manage::onaddButtonClicke()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    if (db1.isOpen()) {
        db1.close();
    }
    add_table *add_tableDialog=new add_table(this,m_comment);
    add_tableDialog->show();
}

void manage::onselecttableButtonClikce()
{
    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    if (db1.isOpen()) {
        db1.close();
    }
    select_table *select_tableDialog =new select_table(this,m_comment);
    select_tableDialog->show();
}

void manage::onlogButtonClickee()
{  if (m_comment != "管理员") {
        QMessageBox::information(this, "提示", "您不是管理员，无法执行此操作！");
        return;
    }

    QSqlDatabase::removeDatabase("manageUniqueConnectionName");
    journal *journalDialog = new journal;
    journalDialog->show();
}

void manage::on_comboBox_currentIndexChanged()
{
    // QString tableName = ui->comboBox->itemText(index);
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
