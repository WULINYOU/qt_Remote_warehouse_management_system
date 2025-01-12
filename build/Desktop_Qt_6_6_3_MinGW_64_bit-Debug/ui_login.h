/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_login;
    QPushButton *btn_registec;
    QPushButton *btn_exit;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(400, 300);
        widget = new QWidget(login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 60, 301, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217")});
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        username = new QLineEdit(widget);
        username->setObjectName("username");

        verticalLayout->addWidget(username);

        password = new QLineEdit(widget);
        password->setObjectName("password");

        verticalLayout->addWidget(password);

        widget1 = new QWidget(login);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(22, 200, 301, 31));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_login = new QPushButton(widget1);
        btn_login->setObjectName("btn_login");

        horizontalLayout->addWidget(btn_login);

        btn_registec = new QPushButton(widget1);
        btn_registec->setObjectName("btn_registec");

        horizontalLayout->addWidget(btn_registec);

        btn_exit = new QPushButton(widget1);
        btn_exit->setObjectName("btn_exit");

        horizontalLayout->addWidget(btn_exit);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "\344\273\223\345\272\223\347\256\241\347\220\206\347\231\273\351\231\206\351\241\265\351\235\242", nullptr));
        username->setText(QCoreApplication::translate("login", "\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        password->setText(QCoreApplication::translate("login", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        btn_login->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        btn_registec->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        btn_exit->setText(QCoreApplication::translate("login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
