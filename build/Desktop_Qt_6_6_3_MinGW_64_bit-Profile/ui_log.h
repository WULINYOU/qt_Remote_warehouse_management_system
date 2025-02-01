/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_log
{
public:
    QTextEdit *showlog;
    QPushButton *clear_contents;
    QPushButton *exit;

    void setupUi(QDialog *log)
    {
        if (log->objectName().isEmpty())
            log->setObjectName("log");
        log->resize(982, 311);
        showlog = new QTextEdit(log);
        showlog->setObjectName("showlog");
        showlog->setGeometry(QRect(10, 30, 871, 261));
        clear_contents = new QPushButton(log);
        clear_contents->setObjectName("clear_contents");
        clear_contents->setGeometry(QRect(890, 40, 75, 23));
        exit = new QPushButton(log);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(890, 80, 75, 23));

        retranslateUi(log);

        QMetaObject::connectSlotsByName(log);
    } // setupUi

    void retranslateUi(QDialog *log)
    {
        log->setWindowTitle(QCoreApplication::translate("log", "Dialog", nullptr));
        clear_contents->setText(QCoreApplication::translate("log", "\346\270\205\351\231\244\346\227\245\345\277\227", nullptr));
        exit->setText(QCoreApplication::translate("log", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class log: public Ui_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
