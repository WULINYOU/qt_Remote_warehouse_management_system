/********************************************************************************
** Form generated from reading UI file 'add_table.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_TABLE_H
#define UI_ADD_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_add_table
{
public:
    QPushButton *add_table_ok;
    QPushButton *add_table_clear;
    QPushButton *exit;
    QLabel *label;
    QLineEdit *newtable_name;
    QTableWidget *tableWidget;
    QPushButton *add;
    QPushButton *delete_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *add_table)
    {
        if (add_table->objectName().isEmpty())
            add_table->setObjectName("add_table");
        add_table->resize(870, 367);
        add_table_ok = new QPushButton(add_table);
        add_table_ok->setObjectName("add_table_ok");
        add_table_ok->setGeometry(QRect(80, 310, 75, 23));
        add_table_clear = new QPushButton(add_table);
        add_table_clear->setObjectName("add_table_clear");
        add_table_clear->setGeometry(QRect(280, 310, 75, 23));
        exit = new QPushButton(add_table);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(480, 310, 75, 23));
        label = new QLabel(add_table);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 41, 16));
        newtable_name = new QLineEdit(add_table);
        newtable_name->setObjectName("newtable_name");
        newtable_name->setGeometry(QRect(70, 50, 91, 21));
        tableWidget = new QTableWidget(add_table);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 90, 631, 191));
        add = new QPushButton(add_table);
        add->setObjectName("add");
        add->setGeometry(QRect(680, 110, 75, 23));
        delete_2 = new QPushButton(add_table);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(680, 160, 75, 23));
        checkBox = new QCheckBox(add_table);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(690, 200, 61, 21));

        retranslateUi(add_table);

        QMetaObject::connectSlotsByName(add_table);
    } // setupUi

    void retranslateUi(QDialog *add_table)
    {
        add_table->setWindowTitle(QCoreApplication::translate("add_table", "Dialog", nullptr));
        add_table_ok->setText(QCoreApplication::translate("add_table", "\347\241\256\350\256\244\345\210\233\345\273\272", nullptr));
        add_table_clear->setText(QCoreApplication::translate("add_table", "\351\207\215\347\275\256\345\206\205\345\256\271", nullptr));
        exit->setText(QCoreApplication::translate("add_table", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("add_table", "\346\226\260\350\241\250\345\220\215", nullptr));
        add->setText(QCoreApplication::translate("add_table", "\346\267\273\345\212\240\345\210\227", nullptr));
        delete_2->setText(QCoreApplication::translate("add_table", "\345\210\240\351\231\244\345\210\227", nullptr));
        checkBox->setText(QCoreApplication::translate("add_table", "\344\270\273\351\224\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_table: public Ui_add_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TABLE_H
