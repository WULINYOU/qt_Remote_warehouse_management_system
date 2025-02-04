/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QPushButton *btn_exit;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 120, 351, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\345\256\213\344\275\223")});
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        username = new QLineEdit(layoutWidget);
        username->setObjectName("username");

        verticalLayout->addWidget(username);

        password = new QLineEdit(layoutWidget);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(password);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(50, 280, 351, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_login = new QPushButton(layoutWidget1);
        btn_login->setObjectName("btn_login");

        horizontalLayout->addWidget(btn_login);

        btn_register = new QPushButton(layoutWidget1);
        btn_register->setObjectName("btn_register");

        horizontalLayout->addWidget(btn_register);

        btn_exit = new QPushButton(layoutWidget1);
        btn_exit->setObjectName("btn_exit");

        horizontalLayout->addWidget(btn_exit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 220, 31, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 250, 31, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\273\223\345\272\223\347\256\241\347\220\206\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        username->setText(QString());
        password->setText(QString());
        btn_login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        btn_register->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
