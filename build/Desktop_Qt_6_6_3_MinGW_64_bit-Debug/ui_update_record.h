/********************************************************************************
** Form generated from reading UI file 'update_record.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_RECORD_H
#define UI_UPDATE_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_update_record
{
public:
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *update_record)
    {
        if (update_record->objectName().isEmpty())
            update_record->setObjectName("update_record");
        update_record->resize(797, 345);
        tableWidget = new QTableWidget(update_record);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 40, 631, 261));
        comboBox = new QComboBox(update_record);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 10, 69, 22));
        pushButton = new QPushButton(update_record);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(680, 150, 91, 41));
        pushButton_2 = new QPushButton(update_record);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(680, 250, 91, 41));

        retranslateUi(update_record);

        QMetaObject::connectSlotsByName(update_record);
    } // setupUi

    void retranslateUi(QDialog *update_record)
    {
        update_record->setWindowTitle(QCoreApplication::translate("update_record", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("update_record", "\346\233\264\346\226\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("update_record", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update_record: public Ui_update_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_RECORD_H
