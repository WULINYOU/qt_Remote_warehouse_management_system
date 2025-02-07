/********************************************************************************
** Form generated from reading UI file 'skin_peeler.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKIN_PEELER_H
#define UI_SKIN_PEELER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_skin_peeler
{
public:
    QRadioButton *write;
    QRadioButton *black;

    void setupUi(QDialog *skin_peeler)
    {
        if (skin_peeler->objectName().isEmpty())
            skin_peeler->setObjectName("skin_peeler");
        skin_peeler->resize(326, 174);
        write = new QRadioButton(skin_peeler);
        write->setObjectName("write");
        write->setGeometry(QRect(60, 40, 95, 19));
        black = new QRadioButton(skin_peeler);
        black->setObjectName("black");
        black->setGeometry(QRect(60, 70, 95, 19));

        retranslateUi(skin_peeler);

        QMetaObject::connectSlotsByName(skin_peeler);
    } // setupUi

    void retranslateUi(QDialog *skin_peeler)
    {
        skin_peeler->setWindowTitle(QCoreApplication::translate("skin_peeler", "\346\215\242\350\202\244", nullptr));
        write->setText(QCoreApplication::translate("skin_peeler", "\347\231\275\345\244\251", nullptr));
        black->setText(QCoreApplication::translate("skin_peeler", "\345\244\234\346\231\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class skin_peeler: public Ui_skin_peeler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKIN_PEELER_H
