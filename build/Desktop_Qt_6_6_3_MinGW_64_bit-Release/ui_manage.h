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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_manage
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QComboBox *comboBox;

    void setupUi(QDialog *manage)
    {
        if (manage->objectName().isEmpty())
            manage->setObjectName("manage");
        manage->resize(479, 333);
        tableWidget = new QTableWidget(manage);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 50, 371, 251));
        pushButton = new QPushButton(manage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(84, 10, 41, 23));
        pushButton_2 = new QPushButton(manage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 10, 75, 23));
        pushButton_3 = new QPushButton(manage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(210, 10, 75, 23));
        pushButton_4 = new QPushButton(manage);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(300, 10, 75, 23));
        pushButton_5 = new QPushButton(manage);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(390, 10, 75, 23));
        pushButton_6 = new QPushButton(manage);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(390, 50, 75, 23));
        pushButton_7 = new QPushButton(manage);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(390, 100, 75, 23));
        pushButton_8 = new QPushButton(manage);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(390, 150, 75, 23));
        pushButton_9 = new QPushButton(manage);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(390, 190, 75, 23));
        pushButton_10 = new QPushButton(manage);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(390, 250, 75, 23));
        comboBox = new QComboBox(manage);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 10, 69, 22));

        retranslateUi(manage);

        QMetaObject::connectSlotsByName(manage);
    } // setupUi

    void retranslateUi(QDialog *manage)
    {
        manage->setWindowTitle(QCoreApplication::translate("manage", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("manage", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("manage", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("manage", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
        pushButton_4->setText(QCoreApplication::translate("manage", "\346\233\264\346\224\271\350\256\260\345\275\225", nullptr));
        pushButton_5->setText(QCoreApplication::translate("manage", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        pushButton_6->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        pushButton_7->setText(QCoreApplication::translate("manage", "\346\226\260\345\273\272\350\241\250", nullptr));
        pushButton_8->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\241\250", nullptr));
        pushButton_9->setText(QCoreApplication::translate("manage", "\345\257\274\345\207\272\350\241\250", nullptr));
        pushButton_10->setText(QCoreApplication::translate("manage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manage: public Ui_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
