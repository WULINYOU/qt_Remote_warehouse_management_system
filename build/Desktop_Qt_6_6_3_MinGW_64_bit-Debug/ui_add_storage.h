/********************************************************************************
** Form generated from reading UI file 'add_storage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_STORAGE_H
#define UI_ADD_STORAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_Storage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Storage_oldok;
    QPushButton *Storage_newok;
    QPushButton *Storage_exit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateTimeEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *add_Storage)
    {
        if (add_Storage->objectName().isEmpty())
            add_Storage->setObjectName("add_Storage");
        add_Storage->resize(500, 290);
        layoutWidget = new QWidget(add_Storage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(340, 20, 131, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Storage_oldok = new QPushButton(layoutWidget);
        Storage_oldok->setObjectName("Storage_oldok");

        verticalLayout->addWidget(Storage_oldok);

        Storage_newok = new QPushButton(layoutWidget);
        Storage_newok->setObjectName("Storage_newok");
        Storage_newok->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(Storage_newok);

        Storage_exit = new QPushButton(layoutWidget);
        Storage_exit->setObjectName("Storage_exit");

        verticalLayout->addWidget(Storage_exit);

        layoutWidget1 = new QWidget(add_Storage);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(21, 20, 261, 251));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        comboBox_2 = new QComboBox(layoutWidget1);
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_4->addWidget(comboBox_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        lineEdit_3 = new QDateTimeEdit(layoutWidget1);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        lineEdit_3->setCalendarPopup(true);

        horizontalLayout_5->addWidget(lineEdit_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        lineEdit_5 = new QLineEdit(layoutWidget1);
        lineEdit_5->setObjectName("lineEdit_5");

        horizontalLayout_6->addWidget(lineEdit_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        lineEdit_4 = new QLineEdit(layoutWidget1);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_7->addWidget(lineEdit_4);


        verticalLayout_2->addLayout(horizontalLayout_7);


        retranslateUi(add_Storage);
        QObject::connect(Storage_newok, &QPushButton::clicked, add_Storage, qOverload<>(&QDialog::on_Storage_new_ok_clicked));

        QMetaObject::connectSlotsByName(add_Storage);
    } // setupUi

    void retranslateUi(QDialog *add_Storage)
    {
        add_Storage->setWindowTitle(QCoreApplication::translate("add_Storage", "Dialog", nullptr));
        Storage_oldok->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\345\216\237\346\234\211\344\272\247\345\223\201", nullptr));
        Storage_newok->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\346\226\260\344\272\247\345\223\201", nullptr));
        Storage_exit->setText(QCoreApplication::translate("add_Storage", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QCoreApplication::translate("add_Storage", "\351\200\211\346\213\251\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\344\272\247\345\223\201\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\346\225\260\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\347\261\273\345\236\213", nullptr));
        label_4->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\346\227\266\351\227\264", nullptr));
        label_7->setText(QCoreApplication::translate("add_Storage", "\345\205\245\345\272\223\345\221\230", nullptr));
        label_6->setText(QCoreApplication::translate("add_Storage", "\344\273\267\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_Storage: public Ui_add_Storage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_STORAGE_H
