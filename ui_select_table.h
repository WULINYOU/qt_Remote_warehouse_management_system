/********************************************************************************
** Form generated from reading UI file 'select_table.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_TABLE_H
#define UI_SELECT_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_select_table
{
public:
    QPushButton *select_table_ok;
    QPushButton *exit;
    QTableWidget *tableWidget;
    QLineEdit *tablename;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *select_table)
    {
        if (select_table->objectName().isEmpty())
            select_table->setObjectName("select_table");
        select_table->resize(400, 300);
        select_table_ok = new QPushButton(select_table);
        select_table_ok->setObjectName("select_table_ok");
        select_table_ok->setGeometry(QRect(300, 40, 75, 23));
        exit = new QPushButton(select_table);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(300, 70, 75, 23));
        tableWidget = new QTableWidget(select_table);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 90, 256, 192));
        tablename = new QLineEdit(select_table);
        tablename->setObjectName("tablename");
        tablename->setGeometry(QRect(150, 40, 113, 21));
        label = new QLabel(select_table);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 91, 31));
        label_2 = new QLabel(select_table);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 53, 15));

        retranslateUi(select_table);

        QMetaObject::connectSlotsByName(select_table);
    } // setupUi

    void retranslateUi(QDialog *select_table)
    {
        select_table->setWindowTitle(QCoreApplication::translate("select_table", "\346\237\245\350\257\242\350\241\250", nullptr));
        select_table_ok->setText(QCoreApplication::translate("select_table", "\346\237\245\350\257\242", nullptr));
        exit->setText(QCoreApplication::translate("select_table", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("select_table", "\346\237\245\350\257\242\346\214\207\345\256\232\350\241\250\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("select_table", "\350\241\250\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_table: public Ui_select_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_TABLE_H
