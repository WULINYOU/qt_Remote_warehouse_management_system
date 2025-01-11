/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manage
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;

    void setupUi(QDialog *manage)
    {
        if (manage->objectName().isEmpty())
            manage->setObjectName("manage");
        manage->resize(678, 397);
        tableWidget = new QTableWidget(manage);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 50, 491, 321));
        pushButton = new QPushButton(manage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 20, 41, 23));
        comboBox = new QComboBox(manage);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(50, 20, 131, 22));
        widget = new QWidget(manage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(510, 50, 161, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout->addWidget(pushButton_6);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout->addWidget(pushButton_8);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout_2->addWidget(pushButton_7);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName("pushButton_9");

        horizontalLayout_3->addWidget(pushButton_9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_10 = new QPushButton(widget);
        pushButton_10->setObjectName("pushButton_10");

        horizontalLayout_4->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(manage);

        QMetaObject::connectSlotsByName(manage);
    } // setupUi

    void retranslateUi(QDialog *manage)
    {
        manage->setWindowTitle(QCoreApplication::translate("manage", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("manage", "\347\241\256\345\256\232", nullptr));
        pushButton_6->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        pushButton_8->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\241\250", nullptr));
        pushButton_5->setText(QCoreApplication::translate("manage", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        pushButton_7->setText(QCoreApplication::translate("manage", "\346\226\260\345\273\272\350\241\250", nullptr));
        pushButton_4->setText(QCoreApplication::translate("manage", "\346\233\264\346\224\271\350\256\260\345\275\225", nullptr));
        pushButton_9->setText(QCoreApplication::translate("manage", "\345\257\274\345\207\272\350\241\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("manage", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        pushButton_10->setText(QCoreApplication::translate("manage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manage: public Ui_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
