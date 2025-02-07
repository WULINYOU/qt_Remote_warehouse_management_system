/********************************************************************************
** Form generated from reading UI file 'select_record.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_RECORD_H
#define UI_SELECT_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_select_record
{
public:
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QComboBox *comboBox2;
    QTableWidget *tableWidget;
    QPushButton *select;
    QPushButton *exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *select_record)
    {
        if (select_record->objectName().isEmpty())
            select_record->setObjectName("select_record");
        select_record->resize(429, 322);
        comboBox = new QComboBox(select_record);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(90, 20, 91, 21));
        lineEdit = new QLineEdit(select_record);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 80, 113, 21));
        comboBox2 = new QComboBox(select_record);
        comboBox2->setObjectName("comboBox2");
        comboBox2->setGeometry(QRect(90, 50, 69, 22));
        tableWidget = new QTableWidget(select_record);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 110, 241, 191));
        select = new QPushButton(select_record);
        select->setObjectName("select");
        select->setGeometry(QRect(300, 30, 101, 61));
        exit = new QPushButton(select_record);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(300, 170, 101, 71));
        label = new QLabel(select_record);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 53, 15));
        label_2 = new QLabel(select_record);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 53, 15));
        label_3 = new QLabel(select_record);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 80, 53, 15));

        retranslateUi(select_record);

        QMetaObject::connectSlotsByName(select_record);
    } // setupUi

    void retranslateUi(QDialog *select_record)
    {
        select_record->setWindowTitle(QCoreApplication::translate("select_record", "\346\237\245\350\257\242\350\256\260\345\275\225", nullptr));
        select->setText(QCoreApplication::translate("select_record", "\346\237\245\350\257\242", nullptr));
        exit->setText(QCoreApplication::translate("select_record", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("select_record", "\351\200\211\346\213\251\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("select_record", "\351\200\211\346\213\251\345\261\236\346\200\247", nullptr));
        label_3->setText(QCoreApplication::translate("select_record", "\346\214\207\345\256\232\346\235\241\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_record: public Ui_select_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_RECORD_H
