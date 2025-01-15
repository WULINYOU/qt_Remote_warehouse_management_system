#include "ui_update_record.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QTabWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDateTimeEdit>
#include <QTableView>
#include "update_record.h"
#include <QSqlDatabase>

update_record::update_record(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::update_record)
{
    ui->setupUi(this);
    QString connectionName = "update_recordName"; // 使用唯一的连接名称
    if(!QSqlDatabase::contains(connectionName)){
        db3 = QSqlDatabase::addDatabase("QODBC", connectionName);
        db3.setDatabaseName("MySQLDSN");
        if(!db3.open()){
            QMessageBox::information(this,"infor","连接数据库失败");
            qDebug()<<"err"<<db3.lastError().text();
        }
    } else {
        db3 = QSqlDatabase::database(connectionName);
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    QSqlQuery query("SHOW TABLES", db3);
    while (query.next()) {
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    QTableWidgetItem *item[10];
    int nCount = ui->tableWidget->rowCount();
    if (nCount < 10) {
        ui->tableWidget->insertRow(nCount);
        item[0] = new QTableWidgetItem(QString::number(nCount + 1)); // 添加序号
        ui->tableWidget->setItem(nCount, 0, item[0]);
    }
    initializeDateTimePickers(nCount);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &update_record::on_comboBox_currentIndexChanged);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &update_record::showDateTimePicker);
    connect(ui->update_button, &QPushButton::clicked, this, &update_record::on_updateButtonClicked);
    connect(ui->exit_button, &QPushButton::clicked, this, &update_record::exitButtonClicked);
    if (!db3.isOpen()) {
        QMessageBox::information(this, "Error", "数据库未打开！");
        qDebug() << "Database is not open!";
        return;
    }
    db3.setConnectOptions("AUTOCOMMIT=1"); // 确保自动提交事务
}

update_record::~update_record()
{
    if (db3.isOpen()) {
        db3.close();
    }
    QSqlDatabase::removeDatabase(db3.connectionName()); // 移除数据库连接
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
            for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
                if (ui->tableWidget->horizontalHeaderItem(col)->text() == "type") {
                    QComboBox *comboBox = new QComboBox();
                    comboBox->addItem("      ");
                    comboBox->addItem("成品库存");
                    comboBox->addItem("退货库存");
                    comboBox->addItem("季节性库存");
                    // 获取原有数据并设置到 QComboBox 中
                    QString currentValue = ui->tableWidget->item(rowCount, col)->text();
                    comboBox->setCurrentText(currentValue);
                    ui->tableWidget->setCellWidget(rowCount, col, comboBox);
                }
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
    QString tableName = ui->comboBox->itemText(index);
    loadData();
}

void update_record::initializeDateTimePickers(int row)
{
    for(int col = 0; col < ui->tableWidget->columnCount(); col++) {
        QTableWidgetItem *headerItem = ui->tableWidget->horizontalHeaderItem(col);
        if(headerItem && headerItem->text().contains("time", Qt::CaseInsensitive)) {
            qDebug() << "Found column with 'time' in its name at index:" << col;
            showDateTimePicker(row, col);
        }
    }
}

void update_record::showDateTimePicker(int row, int col)
{
    if (ui->tableWidget->horizontalHeaderItem(col)->text().contains("time", Qt::CaseInsensitive)) {
        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit->setDateTime(QDateTime::currentDateTime());

        // 将 QDateTimeEdit 设置为表格中的单元格小部件
        ui->tableWidget->setCellWidget(row, col, dateTimeEdit);

        // 显示日期时间选择器
        dateTimeEdit->show();

        connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [this, row, col, dateTimeEdit]() {
            QString dateTimeString = dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(dateTimeString));
            ui->tableWidget->removeCellWidget(row, col); // 删除 QDateTimeEdit 小部件
            dateTimeEdit->deleteLater();
        });
    }
}

void update_record::on_updateButtonClicked()
{
    QString tableName = ui->comboBox->currentText();
    QSqlQuery query(db3);

    // 获取表的记录结构
    query.prepare(QString("SELECT * FROM %1 LIMIT 0").arg(tableName));
    if (!query.exec()) {
        QMessageBox::information(this, "Error", "无法获取表结构: " + query.lastError().text());
        qDebug() << "Error retrieving table structure:" << query.lastError().text();
        return;
    }
    QSqlRecord record = query.record();

    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        QString id = ui->tableWidget->item(row, 0)->text();
        if (id.isEmpty()) {
            QMessageBox::information(this, "Error", "序号为空，无法更新记录！");
            return;
        }

        QHash<QString, QString> data;

        for (int col = 1; col < ui->tableWidget->columnCount(); col++) {
            QString columnName = ui->tableWidget->horizontalHeaderItem(col)->text();
            QTableWidgetItem *item = ui->tableWidget->item(row, col);

            QString value;
            if (item) {
                value = item->text();
            } else {
                // 处理项为空的情况
                value = "";
            }

            // 处理时间字段
            if (columnName.contains("time", Qt::CaseInsensitive)) {
                // 删除时间字符串中的 'T'
                value.remove('T');
                QDateTime dateTime = QDateTime::fromString(value, "yyyy年MM月dd日hh时mm分ss秒");
                if (!dateTime.isValid()) {
                    // 如果解析失败，尝试解析 "yyyy-MM-dd hh:mm:ss" 格式
                    dateTime = QDateTime::fromString(value, "yyyy-MM-dd hh:mm:ss");
                }
                if (!dateTime.isValid()) {
                    QMessageBox::information(this, "Error", QString("时间格式错误: %1").arg(value));
                    qDebug() << "Invalid date time format:" << value;
                    return;
                }
                value = dateTime.toString("yyyy-MM-dd hh:mm:ss");
            }

            data.insert(columnName, value);
        }

        QString sqlWhere = QString("WHERE id=%1").arg(id);
        if (!updateData(tableName, data, sqlWhere)) {
            QMessageBox::information(this, "Error", "更新失败: " + query.lastError().text());
            qDebug() << "Error updating data:" << query.lastError().text();
            return;
        }
    }

    QMessageBox::information(this, "Success", "数据更新成功！");
    loadData(); // 重新加载数据
}

bool update_record::updateData(QString tableName, QHash<QString, QString> data, QString sqlWhere) {
    QString queryStr = "UPDATE " + tableName + " ";
    QHash<QString, QString>::iterator it;
    QString setStr = "SET ";
    for(it = data.begin(); it != data.end(); ++it) {
        setStr += it.key() + "='" + it.value().replace("'", "''") + "',";
    }
    setStr = setStr.left(setStr.length() - 1);
    queryStr += setStr;
    if(!sqlWhere.isEmpty()) {
        queryStr += " " + sqlWhere;
    }
    qDebug() << "Executing SQL:" << queryStr; // 打印SQL语句
    return queryExec(queryStr);
}

bool update_record::queryExec(const QString &queryStr) {
    QSqlQuery query(db3);
    if (!query.exec(queryStr)) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
    return true;
}

void update_record::exitButtonClicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "返回", "确定要返回管理页面?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->close();
    }
}
