/********************************************************************************
** Form generated from reading UI file 'confirmdeletedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDELETEDIALOG_H
#define UI_CONFIRMDELETEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDeleteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *countdownLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *ConfirmDeleteDialog)
    {
        if (ConfirmDeleteDialog->objectName().isEmpty())
            ConfirmDeleteDialog->setObjectName("ConfirmDeleteDialog");
        ConfirmDeleteDialog->resize(300, 95);
        verticalLayout = new QVBoxLayout(ConfirmDeleteDialog);
        verticalLayout->setObjectName("verticalLayout");
        countdownLabel = new QLabel(ConfirmDeleteDialog);
        countdownLabel->setObjectName("countdownLabel");
        countdownLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(countdownLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancelButton = new QPushButton(ConfirmDeleteDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);

        confirmButton = new QPushButton(ConfirmDeleteDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setEnabled(false);

        horizontalLayout->addWidget(confirmButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfirmDeleteDialog);

        QMetaObject::connectSlotsByName(ConfirmDeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDeleteDialog)
    {
        ConfirmDeleteDialog->setWindowTitle(QCoreApplication::translate("ConfirmDeleteDialog", "\347\241\256\350\256\244\345\210\240\351\231\244", nullptr));
        countdownLabel->setText(QCoreApplication::translate("ConfirmDeleteDialog", "\350\257\267\345\234\25010\347\247\222\345\206\205\347\241\256\350\256\244\345\210\240\351\231\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("ConfirmDeleteDialog", "\345\217\226\346\266\210", nullptr));
        confirmButton->setText(QCoreApplication::translate("ConfirmDeleteDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDeleteDialog: public Ui_ConfirmDeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDELETEDIALOG_H
