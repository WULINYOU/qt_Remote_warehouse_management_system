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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <qdiajournal.h>

QT_BEGIN_NAMESPACE

class Ui_journal
{
public:
    QTextEdit *showjournal;
    QPushButton *clear_contents;
    QPushButton *exit;

    void setupUi(QDiajournal *journal)
    {
        if (journal->objectName().isEmpty())
            journal->setObjectName("journal");
        journal->resize(982, 311);
        showjournal = new QTextEdit(journal);
        showjournal->setObjectName("showjournal");
        showjournal->setGeometry(QRect(10, 30, 871, 261));
        clear_contents = new QPushButton(journal);
        clear_contents->setObjectName("clear_contents");
        clear_contents->setGeometry(QRect(890, 40, 75, 23));
        exit = new QPushButton(journal);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(890, 80, 75, 23));

        retranslateUi(journal);

        QMetaObject::connectSlotsByName(journal);
    } // setupUi

    void retranslateUi(QDiajournal *journal)
    {
        journal->setWindowTitle(QCoreApplication::translate("journal", "Diajournal", nullptr));
        clear_contents->setText(QCoreApplication::translate("journal", "\346\270\205\351\231\244\346\227\245\345\277\227", nullptr));
        exit->setText(QCoreApplication::translate("journal", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class journal: public Ui_journal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_H
