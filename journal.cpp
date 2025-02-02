#include "journal.h"
#include "ui_journal.h"
#include <QDialog>
#include <QSqlDatabase>
#include<QMessageBox>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include<QTimer>
#include<QDateTime>
#include <QSqlError>
journal::journal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::journal)
{
    ui->setupUi(this);
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        log_db = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        log_db.setDatabaseName("MySQLDSN");
        if (!log_db.open()) {
            // QMessageBox::information(this, "infor", "�������ݿ�ʧ�ܣ�");
            // qDebug() << "error open database because" << log_db.lastError().text();
        }
    } else {
        log_db = QSqlDatabase::database("manageUniqueConnectionName");
    }
    model=new QSqlTableModel(this,log_db);
    model->setTable("user_logs");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

}

journal::~journal()
{
    if (log_db.isOpen())
        log_db.close();
    delete ui;
}

void journal::logAction(const QString &username, const QString &action)
{
    if (!log_db.open()) {
        qDebug() << "�޷��������ݿ�:" << log_db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO user_logs (username, action, timestamp) VALUES (:username, :action, :timestamp)");
    query.bindValue(":username", username);
    query.bindValue(":action", action);
    query.bindValue(":timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    if (!query.exec()) {
        qDebug() << "������־ʧ��:" << query.lastError().text();
    } else {
        qDebug() << "��־��¼�ɹ�";
    }

    log_db.close();
}
