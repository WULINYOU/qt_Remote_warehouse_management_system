/********************************************************************************
** Form generated from reading UI file 'lessen_storage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LESSEN_STORAGE_H
#define UI_LESSEN_STORAGE_H

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

class Ui_lessen_storage
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout;
    QPushButton *lessen_ok;
    QPushButton *lessen_exit;

    void setupUi(QDialog *lessen_storage)
    {
        if (lessen_storage->objectName().isEmpty())
            lessen_storage->setObjectName("lessen_storage");
        lessen_storage->resize(420, 246);
        widget = new QWidget(lessen_storage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 10, 411, 231));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lessen_ok = new QPushButton(widget);
        lessen_ok->setObjectName("lessen_ok");

        verticalLayout->addWidget(lessen_ok);

        lessen_exit = new QPushButton(widget);
        lessen_exit->setObjectName("lessen_exit");

        verticalLayout->addWidget(lessen_exit);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(lessen_storage);

        QMetaObject::connectSlotsByName(lessen_storage);
    } // setupUi

    void retranslateUi(QDialog *lessen_storage)
    {
        lessen_storage->setWindowTitle(QCoreApplication::translate("lessen_storage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("lessen_storage", "\351\200\211\346\213\251\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("lessen_storage", "\345\207\272\345\272\223\344\272\247\345\223\201\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("lessen_storage", "\346\225\260\351\207\217", nullptr));
        lessen_ok->setText(QCoreApplication::translate("lessen_storage", "\345\207\272\345\272\223", nullptr));
        lessen_exit->setText(QCoreApplication::translate("lessen_storage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lessen_storage: public Ui_lessen_storage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LESSEN_STORAGE_H
