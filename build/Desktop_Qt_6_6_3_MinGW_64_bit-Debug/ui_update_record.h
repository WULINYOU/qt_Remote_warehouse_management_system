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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_update_record
{
public:
    QComboBox *comboBox;
    QPushButton *update_button;
    QPushButton *exit_button;
    QLabel *label_2;
    QLineEdit *name;
    QComboBox *table_element;
    QLineEdit *newword;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *update_record)
    {
        if (update_record->objectName().isEmpty())
            update_record->setObjectName("update_record");
        update_record->resize(389, 224);
        comboBox = new QComboBox(update_record);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(80, 30, 121, 22));
        update_button = new QPushButton(update_record);
        update_button->setObjectName("update_button");
        update_button->setGeometry(QRect(250, 40, 91, 41));
        exit_button = new QPushButton(update_record);
        exit_button->setObjectName("exit_button");
        exit_button->setGeometry(QRect(250, 140, 91, 41));
        label_2 = new QLabel(update_record);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 70, 31, 21));
        name = new QLineEdit(update_record);
        name->setObjectName("name");
        name->setGeometry(QRect(80, 70, 113, 21));
        table_element = new QComboBox(update_record);
        table_element->setObjectName("table_element");
        table_element->setGeometry(QRect(80, 110, 121, 21));
        newword = new QLineEdit(update_record);
        newword->setObjectName("newword");
        newword->setGeometry(QRect(80, 160, 113, 21));
        label_3 = new QLabel(update_record);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 110, 53, 15));
        label_4 = new QLabel(update_record);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 71, 21));
        label_5 = new QLabel(update_record);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 40, 53, 15));

        retranslateUi(update_record);

        QMetaObject::connectSlotsByName(update_record);
    } // setupUi

    void retranslateUi(QDialog *update_record)
    {
        update_record->setWindowTitle(QCoreApplication::translate("update_record", "Dialog", nullptr));
        update_button->setText(QCoreApplication::translate("update_record", "\346\233\264\346\226\260", nullptr));
        exit_button->setText(QCoreApplication::translate("update_record", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("update_record", "\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("update_record", "\345\261\236\346\200\247\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("update_record", "\346\233\264\346\224\271\347\232\204\346\226\260\345\200\274", nullptr));
        label_5->setText(QCoreApplication::translate("update_record", "\344\275\234\347\224\250\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update_record: public Ui_update_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_RECORD_H
