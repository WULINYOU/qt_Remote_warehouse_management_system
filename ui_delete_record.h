/********************************************************************************
** Form generated from reading UI file 'delete_record.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_RECORD_H
#define UI_DELETE_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_delete_record
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *agagin_name;
    QVBoxLayout *verticalLayout;
    QPushButton *first_sure;
    QPushButton *exit;

    void setupUi(QDialog *delete_record)
    {
        if (delete_record->objectName().isEmpty())
            delete_record->setObjectName("delete_record");
        delete_record->resize(358, 197);
        layoutWidget = new QWidget(delete_record);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 40, 351, 121));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        name = new QLineEdit(layoutWidget);
        name->setObjectName("name");

        horizontalLayout_3->addWidget(name);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        agagin_name = new QLineEdit(layoutWidget);
        agagin_name->setObjectName("agagin_name");

        horizontalLayout_2->addWidget(agagin_name);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        first_sure = new QPushButton(layoutWidget);
        first_sure->setObjectName("first_sure");

        verticalLayout->addWidget(first_sure);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName("exit");

        verticalLayout->addWidget(exit);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(delete_record);

        QMetaObject::connectSlotsByName(delete_record);
    } // setupUi

    void retranslateUi(QDialog *delete_record)
    {
        delete_record->setWindowTitle(QCoreApplication::translate("delete_record", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("delete_record", "\351\200\211\346\213\251\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("delete_record", "\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("delete_record", "\351\207\215\346\226\260\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        first_sure->setText(QCoreApplication::translate("delete_record", "\347\241\256\345\256\232\345\210\240\351\231\244", nullptr));
        exit->setText(QCoreApplication::translate("delete_record", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_record: public Ui_delete_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_RECORD_H
