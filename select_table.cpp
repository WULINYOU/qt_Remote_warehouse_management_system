#include "select_table.h"
#include "ui_select_table.h"
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
select_table::select_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::select_table)
{
    ui->setupUi(this);
    // ������ݿ������Ƿ��Ѿ�����
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        db10 = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        db10.setDatabaseName("MySQLDSN");
        if (!db10.open()) {
            QMessageBox::information(this, "infor", "�������ݿ�ʧ�ܣ�");
            qDebug() << "error open database because" << db10.lastError().text();
        }
    } else {
        db10 = QSqlDatabase::database("manageUniqueConnectionName");
    }

    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setAlternatingRowColors(true);
    connect(ui->select_table_ok,&QPushButton::clicked,this,&select_table::onselectButtonClick);
}

select_table::~select_table()
{
    delete ui;
}

void select_table::onselectButtonClick()
{
    QString tableName = ui->tablename->text().trimmed();

    // Step 1: ��ȡ�������
    QSqlQuery columnQuery(db10);
    columnQuery.prepare("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = :tableName");
    columnQuery.bindValue(":tableName", tableName);

    if (!columnQuery.exec()) {
        QMessageBox::information(this, "infor", "��ѯʧ��");
        qDebug() << "Error fetching columns:" << columnQuery.lastError();
        return;
    }

    QStringList columnNames;
    while (columnQuery.next()) {
        columnNames << columnQuery.value(0).toString();
    }

    // Step 2: ��ѯ�������
    QSqlQuery dataQuery(db10);
    QString queryStr = QString("SELECT * FROM %1").arg(tableName);
    if (!dataQuery.exec(queryStr)) {
        qDebug() << "Error fetching data:" << dataQuery.lastError();
        return;
    }

    // Step 3: ���� tableWidget �ı�ͷ
    ui->tableWidget->setColumnCount(columnNames.size());
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);

    // Step 4: ������ݵ� tableWidget
    int rowCount = 0;
    while (dataQuery.next()) {
        ui->tableWidget->insertRow(rowCount);
        for (int col = 0; col < columnNames.size(); ++col) {
            QVariant value = dataQuery.value(col);
            QString itemText;
            if (value.metaType().id() == QMetaType::QDateTime) {
                QDateTime dateTime = value.toDateTime();
                itemText = dateTime.toString("yyyy��MM��dd��Thhʱmm��ss��");
            } else {
                itemText = value.toString();
            }
            QTableWidgetItem *item = new QTableWidgetItem(itemText);
            ui->tableWidget->setItem(rowCount, col, item);
        }
        rowCount++;
    }

    // �����п�����Ӧ����
    ui->tableWidget->resizeColumnsToContents();
}

void select_table::onExitButtonClicke()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"����","ȷ��Ҫ���ع���ҳ��?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        this->close();
    }
}
