/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manage
{
public:
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *delete_record;
    QPushButton *delete_table;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *update_record;
    QPushButton *export_table;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *select_record;
    QPushButton *add_table;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *add_record;
    QPushButton *manage_Exit;
    QLabel *time_label;
    QPushButton *refresh;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Storage;
    QPushButton *lessen;

    void setupUi(QDialog *manage)
    {
        if (manage->objectName().isEmpty())
            manage->setObjectName("manage");
        manage->resize(908, 514);
        tableWidget = new QTableWidget(manage);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 50, 571, 441));
        comboBox = new QComboBox(manage);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(50, 20, 131, 22));
        layoutWidget = new QWidget(manage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(620, 50, 261, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        delete_record = new QPushButton(layoutWidget);
        delete_record->setObjectName("delete_record");

        horizontalLayout->addWidget(delete_record);

        delete_table = new QPushButton(layoutWidget);
        delete_table->setObjectName("delete_table");

        horizontalLayout->addWidget(delete_table);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        update_record = new QPushButton(layoutWidget);
        update_record->setObjectName("update_record");

        horizontalLayout_3->addWidget(update_record);

        export_table = new QPushButton(layoutWidget);
        export_table->setObjectName("export_table");

        horizontalLayout_3->addWidget(export_table);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        select_record = new QPushButton(layoutWidget);
        select_record->setObjectName("select_record");

        horizontalLayout_2->addWidget(select_record);

        add_table = new QPushButton(layoutWidget);
        add_table->setObjectName("add_table");

        horizontalLayout_2->addWidget(add_table);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        add_record = new QPushButton(layoutWidget);
        add_record->setObjectName("add_record");

        horizontalLayout_4->addWidget(add_record);

        manage_Exit = new QPushButton(layoutWidget);
        manage_Exit->setObjectName("manage_Exit");

        horizontalLayout_4->addWidget(manage_Exit);


        verticalLayout->addLayout(horizontalLayout_4);

        time_label = new QLabel(manage);
        time_label->setObjectName("time_label");
        time_label->setGeometry(QRect(580, 20, 311, 21));
        refresh = new QPushButton(manage);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(500, 20, 75, 23));
        widget = new QWidget(manage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(610, 460, 281, 51));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Storage = new QPushButton(widget);
        Storage->setObjectName("Storage");

        horizontalLayout_5->addWidget(Storage);

        lessen = new QPushButton(widget);
        lessen->setObjectName("lessen");

        horizontalLayout_5->addWidget(lessen);


        retranslateUi(manage);

        QMetaObject::connectSlotsByName(manage);
    } // setupUi

    void retranslateUi(QDialog *manage)
    {
        manage->setWindowTitle(QCoreApplication::translate("manage", "Dialog", nullptr));
        delete_record->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        delete_table->setText(QCoreApplication::translate("manage", "\345\210\240\351\231\244\350\241\250", nullptr));
        update_record->setText(QCoreApplication::translate("manage", "\346\233\264\346\224\271\350\256\260\345\275\225", nullptr));
        export_table->setText(QCoreApplication::translate("manage", "\345\257\274\345\207\272\350\241\250", nullptr));
        select_record->setText(QCoreApplication::translate("manage", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        add_table->setText(QCoreApplication::translate("manage", "\346\226\260\345\273\272\350\241\250", nullptr));
        add_record->setText(QCoreApplication::translate("manage", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        manage_Exit->setText(QCoreApplication::translate("manage", "\351\200\200\345\207\272", nullptr));
        time_label->setText(QString());
        refresh->setText(QCoreApplication::translate("manage", "\345\210\267\346\226\260", nullptr));
        Storage->setText(QCoreApplication::translate("manage", "\345\205\245\345\272\223", nullptr));
        lessen->setText(QCoreApplication::translate("manage", "\345\207\272\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manage: public Ui_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
