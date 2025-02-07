/********************************************************************************
** Form generated from reading UI file 'delete_table.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_TABLE_H
#define UI_DELETE_TABLE_H

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

class Ui_delete_table
{
public:
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QLineEdit *tablename;
    QLabel *label;
    QLabel *label_2;
    QPushButton *delete_table_ok;
    QPushButton *exit;

    void setupUi(QDialog *delete_table)
    {
        if (delete_table->objectName().isEmpty())
            delete_table->setObjectName("delete_table");
        delete_table->resize(453, 262);
        tableWidget = new QTableWidget(delete_table);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 40, 301, 201));
        comboBox = new QComboBox(delete_table);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 10, 111, 21));
        tablename = new QLineEdit(delete_table);
        tablename->setObjectName("tablename");
        tablename->setGeometry(QRect(330, 40, 113, 21));
        label = new QLabel(delete_table);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 53, 15));
        label_2 = new QLabel(delete_table);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 20, 53, 15));
        delete_table_ok = new QPushButton(delete_table);
        delete_table_ok->setObjectName("delete_table_ok");
        delete_table_ok->setGeometry(QRect(340, 70, 91, 51));
        exit = new QPushButton(delete_table);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(340, 150, 91, 51));

        retranslateUi(delete_table);

        QMetaObject::connectSlotsByName(delete_table);
    } // setupUi

    void retranslateUi(QDialog *delete_table)
    {
        delete_table->setWindowTitle(QCoreApplication::translate("delete_table", "\345\210\240\351\231\244\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("delete_table", "\351\200\211\346\213\251\350\241\250\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("delete_table", "\346\214\207\345\256\232\350\241\250\345\220\215", nullptr));
        delete_table_ok->setText(QCoreApplication::translate("delete_table", "\347\241\256\350\256\244\345\210\240\351\231\244", nullptr));
        exit->setText(QCoreApplication::translate("delete_table", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_table: public Ui_delete_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_TABLE_H
