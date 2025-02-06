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
#include<QDateTimeEdit>
#include<QTableView>
#include"journal.h"
add_record::add_record(QWidget *parent, const QString &comment)
    : QDialog(parent)
    , ui(new Ui::add_record)
    , timer(new QTimer(this))
    , m_journal (new journal(this))
    , m_comment(comment)
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
        initializeDateTimePickers(nCount);
    });
    // 添加信号连接，当单元格被双击时显示日期时间选择器
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &add_record::showDateTimePicker);
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
    connect(ui->add_ok,&QPushButton::clicked,this,&add_record::add_okButtonClicked);
    timer->start(1000);
}

add_record::~add_record() {
    if (db2.isOpen()) {
        db2.close();
    }
    delete ui;
}

void add_record::on_comboBox_currentIndexChanged(int index) {
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

        int row = 0;
        while (query.next()) {
            for (int col = 0; col < header.size(); col++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tableWidget->setItem(row, col, item);
            }
            row++;
        }
    }
}

void add_record::on_backmanage() {
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"返回","确定要返回管理页面?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}

void add_record::updateShowTimeLabel() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedTime = currentDateTime.toString("系统时间：yyyy年MM月dd日hh时mm分ss秒");
    ui->showtime_label->setText(formattedTime);
}

void add_record::initializeDateTimePickers(int row) {
    for(int col=0; col<ui->tableWidget->columnCount(); col++) {
        QTableWidgetItem *headerItem = ui->tableWidget->horizontalHeaderItem(col);
        if(headerItem && headerItem->text().contains("time", Qt::CaseInsensitive)) {
            qDebug() << "Found column with 'time' in its name at index:" << col;
            showTimetable(row, col);
        }
    }
}

void add_record::showTimetable(int row, int col) {
    // 创建一个 QDateTimeEdit 控件
    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
    dateTimeEdit->setCalendarPopup(true);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    // 将 QDateTimeEdit 设置为表格中的单元格小部件
    ui->tableWidget->setCellWidget(row, col, dateTimeEdit);

    // 连接信号与槽，当日期时间改变时更新表格内容
    connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [this, row, col, dateTimeEdit]() {
        // 更新 QTableWidgetItem 内容
        QTableWidgetItem *item = new QTableWidgetItem(dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->tableWidget->setItem(row, col, item);
        // 从表格中移除 QDateTimeEdit 控件
        ui->tableWidget->removeCellWidget(row, col);

        // 删除不再需要的控件
        dateTimeEdit->deleteLater();
    });
}

void add_record::showDateTimePicker(int row, int col) {
    if (ui->tableWidget->horizontalHeaderItem(col)->text().contains("time", Qt::CaseInsensitive)) {
        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit->setDateTime(QDateTime::currentDateTime());

        // 将 QDateTimeEdit 设置为表格中的单元格小部件
        ui->tableWidget->setCellWidget(row, col, dateTimeEdit);

        // 显示日期时间选择器
        dateTimeEdit->show();

        connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [this, row, col, dateTimeEdit]() {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")));
            dateTimeEdit->deleteLater();
        });
    }
}

void add_record::add_okButtonClicked() {
    QString tableName = ui->comboBox->currentText();

    if (!db2.isOpen()) {
        QMessageBox::information(this, "Error", "数据库未打开！");
        qDebug() << "Database is not open!";
        return;
    }

    QSqlQuery query(db2);
    QString insertQuery = QString("INSERT INTO inventory.%1 (").arg(tableName);
    QStringList columns;
    QStringList values;

    // 获取 comment 值
    QString comment = m_comment;

    qDebug() << "Comment value:" << comment; // 添加调试输出

    for (int col = 1; col < ui->tableWidget->columnCount(); col++) { // 修改: 从第二列开始遍历
        QTableWidgetItem *item = ui->tableWidget->item(ui->tableWidget->rowCount() - 1, col);
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        if (header == "type") {
            QComboBox *comboBox = qobject_cast<QComboBox*>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount() - 1, col));
            if (comboBox) {
                QString type = comboBox->currentText();
                if (type != "成品库存" && type != "退货库存" && type != "季节性库存") {
                    QMessageBox::warning(this, "数据不兼容", "type列只能插入'成品库存'、'退货库存'、'季节性库存'");
                    return;
                }
                columns << header;
                values << QString("'%1'").arg(type);
            } else {
                QMessageBox::warning(this, "数据不兼容", "type列不能为空");
                return;
            }
        } else if (header.contains("time", Qt::CaseInsensitive)) {
            if (item && !QDateTime::fromString(item->text(), "yyyy-MM-dd hh:mm:ss").isValid()) {
                QMessageBox::warning(this, "数据不兼容", QString("%1列只能插入时间格式的数据").arg(header));
                return;
            }
            columns << header;
            // 确保日期时间格式正确
            QString dateTimeStr = item ? item->text() : "";
            if (!dateTimeStr.isEmpty()) {
                QDateTime dateTime = QDateTime::fromString(dateTimeStr, "yyyy-MM-dd hh:mm:ss");
                values << QString("'%1'").arg(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
            } else {
                values << "NULL"; // 如果时间为空，插入NULL
            }
        } else {
            columns << header;
            values << QString("'%1'").arg(item ? item->text() : "");
        }
    }
    insertQuery += columns.join(", ") + ") VALUES (" + values.join(", ") + ")";
    QString logMessage = QString("添加记录到表 %1:\n").arg(tableName);
    for (int i = 0; i < columns.size(); ++i) {
        logMessage += QString("  %1: %2\n").arg(columns[i]).arg(values[i].remove('\'')); // 去掉引号以提高可读性
    }


    if (!query.exec(insertQuery)) {
        QMessageBox::warning(this, "插入失败", query.lastError().text());
        m_journal->logAction(comment, "插入失败");
    } else {
        QMessageBox::information(this, "插入成功", "数据已成功插入到数据库中");
        m_journal->logAction(comment, "插入成功");
        m_journal->logAction(comment, logMessage);
        qDebug() << "Log action called with comment:" << comment << "and action: 插入成功"; // 添加调试输出
    }
}
