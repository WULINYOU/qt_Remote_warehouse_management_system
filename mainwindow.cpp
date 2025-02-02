#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlRecord>
#include"registec.h"
#include"manage.h"
#include"journal.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_journal (new journal(this))
{
    ui->setupUi(this);

    connect(ui->btn_exit,&QPushButton::clicked,this,&MainWindow::onExitButtonClicked);
    connect(ui->btn_login, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);// 添加登录按钮的信号与槽连接
    connect(ui->btn_register,&QPushButton::clicked,this,&MainWindow::onRegisterButtonClicked);  // 添加注册按钮的信号与槽连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExitButtonClicked()
{
    // 显示确认退出对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "退出", "确定要退出吗？",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

void MainWindow::onLoginButtonClicked()
{
    // 获取用户名和密码
    QString username =ui->username->text();
    QString password =ui->password->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");// 连接数据库
    db.setDatabaseName("MySQLDSN-login");  // 使用配置好的 DSN 名称

    bool ok = db.open();
    if (!ok) {
        QMessageBox::information(this, "infor", "连接数据库失败！");
         qDebug() << "error open database because" << db.lastError().text();
        return;
    }
    QSqlQuery query;
    QString sql="SELECT * FROM inventory.login WHERE name= :username AND password = :password";
    query.prepare(sql);
    query.bindValue(":username",username);
    query.bindValue(":password",password);

    if(!query.exec()){

        QMessageBox::information(this,"infor","查询失败");
        qDebug()<<"查询失败Query failed:" << query.lastError().text();
        db.close();
        return;
    }
    if(query.next()){
        QString comment=query.value("comment").toString();
        QMessageBox msgBox;
        msgBox.setWindowTitle("恭喜你");
        msgBox.setText(QString("%1 登录成功").arg(comment));
        m_journal->logAction(comment,"登录成功");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok) {
            manage *manageDialog = new manage(this,comment);
            manageDialog->show();

        }
        }else {
        m_journal->logAction(comment,"登录失败");
        QMessageBox::information(this,"infor","用户名或密码错误");
    }
    db.close();
}

void MainWindow::onRegisterButtonClicked()
{
    registec *registerDialog=new registec;
    registerDialog->show();
}


