/********************************************************************************
** Form generated from reading UI file 'add_record.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_RECORD_H
#define UI_ADD_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_add_record
{
public:
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *add;
    QPushButton *reduce;
    QPushButton *add_ok;
    QPushButton *add_exit;
    QLabel *showtime_label;

    void setupUi(QDialog *add_record)
    {
        if (add_record->objectName().isEmpty())
            add_record->setObjectName("add_record");
        add_record->resize(884, 330);
        comboBox = new QComboBox(add_record);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 40, 101, 22));
        tableWidget = new QTableWidget(add_record);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 691, 161));
        add = new QPushButton(add_record);
        add->setObjectName("add");
        add->setGeometry(QRect(760, 70, 75, 51));
        reduce = new QPushButton(add_record);
        reduce->setObjectName("reduce");
        reduce->setGeometry(QRect(760, 140, 75, 51));
        add_ok = new QPushButton(add_record);
        add_ok->setObjectName("add_ok");
        add_ok->setGeometry(QRect(650, 250, 91, 31));
        add_exit = new QPushButton(add_record);
        add_exit->setObjectName("add_exit");
        add_exit->setGeometry(QRect(760, 250, 81, 31));
        showtime_label = new QLabel(add_record);
        showtime_label->setObjectName("showtime_label");
        showtime_label->setGeometry(QRect(410, 30, 411, 21));

        retranslateUi(add_record);

        QMetaObject::connectSlotsByName(add_record);
    } // setupUi

    void retranslateUi(QDialog *add_record)
    {
        add_record->setWindowTitle(QCoreApplication::translate("add_record", "Dialog", nullptr));
        add->setText(QCoreApplication::translate("add_record", "\345\242\236\345\212\240\350\256\260\345\275\225\350\241\214", nullptr));
        reduce->setText(QCoreApplication::translate("add_record", "\345\207\217\345\260\221\350\256\260\345\275\225\350\241\214", nullptr));
        add_ok->setText(QCoreApplication::translate("add_record", "\346\267\273\345\212\240", nullptr));
        add_exit->setText(QCoreApplication::translate("add_record", "\351\200\200\345\207\272", nullptr));
        showtime_label->setText(QCoreApplication::translate("add_record", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_record: public Ui_add_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_RECORD_H
