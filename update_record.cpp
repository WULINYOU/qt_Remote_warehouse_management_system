#include "update_record.h"
#include "ui_update_record.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QTabWidget>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QDateTimeEdit>
#include<QTableView>
#include<QContextMenuEvent>
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
        QTableWidgetItem *item[10];
        int nCount = ui->tableWidget->rowCount();
        if (nCount < 10) {
            ui->tableWidget->insertRow(nCount);
            item[0] = new QTableWidgetItem(QString::number(nCount + 1)); // 添加序号
            ui->tableWidget->setItem(nCount, 0, item[0]);
        }
        initializeDateTimePickers(nCount);

        connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&update_record::on_comboBox_currentIndexChanged);
        connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this, &update_record::showDateTimePicker);
    }
}

update_record::~update_record()
{
    if (db3.isOpen()) {
        db3.close();
    }
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

void update_record::initializeDateTimePickers(int row)
{
    for(int col=0; col<ui->tableWidget->columnCount(); col++) {
        QTableWidgetItem *headerItem = ui->tableWidget->horizontalHeaderItem(col);
        if(headerItem && headerItem->text().contains("time", Qt::CaseInsensitive)) {
            qDebug() << "Found column with 'time' in its name at index:" << col;
            showTimetable(row, col);
        }
    }
}

void update_record::showTimetable(int row, int col)
{
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

void update_record::showDateTimePicker(int row, int col)
{
    if (ui->tableWidget->horizontalHeaderItem(col)->text().contains("time", Qt::CaseInsensitive)) {
        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit->setDateTime(QDateTime::currentDateTime());

        // 计算单元格的右下角位置
        QRect cellRect = ui->tableWidget->visualRect(ui->tableWidget->indexFromItem(ui->tableWidget->item(row, col)));
        QPoint bottomRight = cellRect.bottomRight();
        QPoint globalPos = ui->tableWidget->viewport()->mapToGlobal(bottomRight);

        // 设置 QDateTimeEdit 的位置为单元格的右下角
        dateTimeEdit->setGeometry(globalPos.x(), globalPos.y(), dateTimeEdit->width(), dateTimeEdit->height());
        dateTimeEdit->show();

        connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [this, row, col, dateTimeEdit]() {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")));

            // 从表格中移除 QDateTimeEdit 控件
            ui->tableWidget->removeCellWidget(row, col);

            // 删除不再需要的控件
            dateTimeEdit->deleteLater();
        });
    }
}

void update_record::contextMenuEvent(QContextMenuEvent *event)
{
    // 忽略右键菜单事件
    event->ignore();
}
