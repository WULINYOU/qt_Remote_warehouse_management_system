#include "registec.h"
#include "ui_registec.h"
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
#include"mainwindow.h"

registec::registec(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registec)
{
    ui->setupUi(this);
connect(ui->btn_make_user, &QPushButton::clicked, this, &registec::onMakeUserButtonClicked); // 添加此行以连接注册按钮的信号与槽连接
connect(ui->btn_back_login,&QPushButton::clicked,this,&registec::onBackloginButtonClicked);
connect(ui-> btn_exit1,&QPushButton::clicked,this,&registec::onExitButtonClicked);

    // 初始化数据库连接
    db = QSqlDatabase::addDatabase("QODBC","uniqueConnectionName"); // 连接数据库
    db.setDatabaseName("MySQLDSN-login");  // 使用配置好的 DSN 名称
    if (!db.open()) {
        QMessageBox::information(this, "infor", "连接数据库失败！");
        qDebug() << "error open database because" << db.lastError().text();
    }
}

registec::~registec()
{
    delete ui;
    if (db.isOpen()) {
        db.close();  // 关闭数据库连接
    }
}

void registec::onMakeUserButtonClicked()
{
    QString username = ui->add_username->text();
    QString password = ui->add_password->text();
    QString confirmPassword = ui->add_password_again->text();
    QString comment = ui->add_comment->text();
    QString inviteCode = ui->ask_number->text();

    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() || comment.isEmpty() || inviteCode.isEmpty()) {
        QMessageBox::warning(this, "错误", "所有信息必须填写！");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "错误", "两次输入密码不一致");
        return;
    }

    if (comment == "请输入中文名称") {
        QMessageBox::warning(this, "错误", "中文名不能这样");
        return;
    }

    QSqlQuery captchaQuery(db);  // 使用已打开的数据库连接
    QString captchaSql = "SELECT * FROM inventory.invite_code WHERE inviteCode = :inviteCode";  // 使用 inviteCode 字段名
    captchaQuery.prepare(captchaSql);
    captchaQuery.bindValue(":inviteCode", inviteCode);

    if (!captchaQuery.exec()) {
        QMessageBox::information(this, "提示", "查询邀请码失败");
        qDebug() << "查询邀请码失败 Query failed:" << captchaQuery.lastError().text();
        return;
    }

    if (!captchaQuery.next()) {
        QMessageBox::warning(this, "错误", "邀请码无效");
        return;
    }

    // 检查 inviteCode 是否已被使用
    QSqlQuery checkInviteCodeQuery(db);
    QString checkInviteCodeSql = "SELECT COUNT(*) FROM inventory.login WHERE invite_code = :invite_code";
    checkInviteCodeQuery.prepare(checkInviteCodeSql);
    checkInviteCodeQuery.bindValue(":invite_code", inviteCode);

    if (!checkInviteCodeQuery.exec()) {
        QMessageBox::information(this, "提示", "检查邀请码失败");
        qDebug() << "检查邀请码失败 Query failed:" << checkInviteCodeQuery.lastError().text();
        return;
    }

    checkInviteCodeQuery.first();  // 移动到第一行结果

    // 插入新用户记录
    QSqlQuery query(db);
    QString sql = "INSERT INTO inventory.login (name, password, comment, invite_code) VALUES (:username, :password, :comment, :invite_code)";
    query.prepare(sql);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":comment", comment);
    query.bindValue(":invite_code", inviteCode);

    if (!query.exec()) {
        QMessageBox::information(this, "提示", "注册失败，出现库中重复记录");
        qDebug() << "注册失败 Query failed:" << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "恭喜你", "注册成功");
    this->close();  // 关闭注册对话框
}


void registec::onBackloginButtonClicked()
{
    // MainWindow *mainWindowDialog=new MainWindow;
    // mainWindowDialog->show();
    // QApplication::quit();
     this->close();
}

void registec::onExitButtonClicked()
{
    QApplication::quit();
}
