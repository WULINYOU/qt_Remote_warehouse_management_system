/********************************************************************************
** Form generated from reading UI file 'journal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNAL_H
#define UI_JOURNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_journal
{
public:
    QPushButton *journal_OK;
    QPushButton *Exit;
    QTableView *tableView;

    void setupUi(QDialog *journal)
    {
        if (journal->objectName().isEmpty())
            journal->setObjectName("journal");
        journal->resize(738, 517);
        journal_OK = new QPushButton(journal);
        journal_OK->setObjectName("journal_OK");
        journal_OK->setGeometry(QRect(30, 20, 75, 23));
        Exit = new QPushButton(journal);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(130, 20, 75, 23));
        tableView = new QTableView(journal);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 60, 701, 441));

        retranslateUi(journal);

        QMetaObject::connectSlotsByName(journal);
    } // setupUi

    void retranslateUi(QDialog *journal)
    {
        journal->setWindowTitle(QCoreApplication::translate("journal", "\346\227\245\345\277\227\350\256\260\345\275\225", nullptr));
        journal_OK->setText(QCoreApplication::translate("journal", "\346\270\205\347\251\272", nullptr));
        Exit->setText(QCoreApplication::translate("journal", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class journal: public Ui_journal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_H
