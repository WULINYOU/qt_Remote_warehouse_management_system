#include "journal.h"
#include "ui_journal.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTimer>
#include <QDateTime>
#include <QSqlError>

journal::journal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::journal)
{
    ui->setupUi(this);

    // 检查数据库连接是否已经存在
    if (!QSqlDatabase::contains("manageUniqueConnectionName")) {
        log_db = QSqlDatabase::addDatabase("QODBC", "manageUniqueConnectionName");
        log_db.setDatabaseName("MySQLDSN");
        if (!log_db.open()) {
            QMessageBox::information(this, "Error", "连接数据库失败！");
            qDebug() << "Error opening database:" << log_db.lastError().text();
        }
    } else {
        log_db = QSqlDatabase::database("manageUniqueConnectionName");
    }

    model = new QSqlTableModel(this, log_db);
    model->setTable("user_logs");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

journal::~journal()
{
    if (log_db.isOpen()) {
        log_db.close();
    }
    delete ui;
}

void journal::logAction(const QString &username, const QString &action)
{
    // 确保数据库连接是打开的
    if (!log_db.isOpen()) {
        if (!log_db.open()) {
            qDebug() << "无法连接数据库:" << log_db.lastError().text();
            return;
        }
    }

    QSqlQuery query(log_db);
    query.prepare("INSERT INTO user_logs (username, action, timestamp) VALUES (:username, :action, :timestamp)");
    query.bindValue(":username", username);
    query.bindValue(":action", action);
    query.bindValue(":timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    if (!query.exec()) {
        qDebug() << "插入日志失败:" << query.lastError().text();
    } else {
        qDebug() << "日志记录成功";
        model->select(); // 刷新模型以显示新插入的日志
    }
}
