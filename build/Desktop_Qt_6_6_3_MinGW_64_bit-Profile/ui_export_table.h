/********************************************************************************
** Form generated from reading UI file 'export_table.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_TABLE_H
#define UI_EXPORT_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_export_table
{
public:
    QPushButton *export_ok;
    QPushButton *exit;
    QComboBox *tablename;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *export_table)
    {
        if (export_table->objectName().isEmpty())
            export_table->setObjectName("export_table");
        export_table->resize(400, 300);
        export_ok = new QPushButton(export_table);
        export_ok->setObjectName("export_ok");
        export_ok->setGeometry(QRect(300, 50, 75, 23));
        exit = new QPushButton(export_table);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(300, 110, 75, 23));
        tablename = new QComboBox(export_table);
        tablename->setObjectName("tablename");
        tablename->setGeometry(QRect(90, 20, 111, 22));
        label = new QLabel(export_table);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 53, 15));
        tableWidget = new QTableWidget(export_table);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 60, 256, 192));

        retranslateUi(export_table);

        QMetaObject::connectSlotsByName(export_table);
    } // setupUi

    void retranslateUi(QDialog *export_table)
    {
        export_table->setWindowTitle(QCoreApplication::translate("export_table", "Dialog", nullptr));
        export_ok->setText(QCoreApplication::translate("export_table", "\345\257\274\345\207\272", nullptr));
        exit->setText(QCoreApplication::translate("export_table", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("export_table", "\351\200\211\346\213\251\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class export_table: public Ui_export_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_TABLE_H
