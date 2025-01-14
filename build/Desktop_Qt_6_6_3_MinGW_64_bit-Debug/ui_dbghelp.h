/********************************************************************************
** Form generated from reading UI file 'dbghelp.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBGHELP_H
#define UI_DBGHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Dbghelp
{
public:

    void setupUi(QDialog *Dbghelp)
    {
        if (Dbghelp->objectName().isEmpty())
            Dbghelp->setObjectName("Dbghelp");
        Dbghelp->resize(400, 300);

        retranslateUi(Dbghelp);

        QMetaObject::connectSlotsByName(Dbghelp);
    } // setupUi

    void retranslateUi(QDialog *Dbghelp)
    {
        Dbghelp->setWindowTitle(QCoreApplication::translate("Dbghelp", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dbghelp: public Ui_Dbghelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBGHELP_H
