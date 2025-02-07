/********************************************************************************
** Form generated from reading UI file 'registec.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTEC_H
#define UI_REGISTEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registec
{
public:
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_back_login;
    QPushButton *btn_make_user;
    QPushButton *btn_exit1;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *add_comment;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *add_username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *add_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *add_password_again;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *ask_number;

    void setupUi(QDialog *registec)
    {
        if (registec->objectName().isEmpty())
            registec->setObjectName("registec");
        registec->resize(400, 300);
        label_6 = new QLabel(registec);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 30, 311, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\350\210\222\344\275\223")});
        font.setPointSize(24);
        label_6->setFont(font);
        layoutWidget = new QWidget(registec);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 230, 239, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_back_login = new QPushButton(layoutWidget);
        btn_back_login->setObjectName("btn_back_login");

        horizontalLayout_6->addWidget(btn_back_login);

        btn_make_user = new QPushButton(layoutWidget);
        btn_make_user->setObjectName("btn_make_user");

        horizontalLayout_6->addWidget(btn_make_user);

        btn_exit1 = new QPushButton(layoutWidget);
        btn_exit1->setObjectName("btn_exit1");

        horizontalLayout_6->addWidget(btn_exit1);

        layoutWidget1 = new QWidget(registec);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 80, 311, 141));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        add_comment = new QLineEdit(layoutWidget1);
        add_comment->setObjectName("add_comment");

        horizontalLayout->addWidget(add_comment);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        add_username = new QLineEdit(layoutWidget1);
        add_username->setObjectName("add_username");

        horizontalLayout_2->addWidget(add_username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        add_password = new QLineEdit(layoutWidget1);
        add_password->setObjectName("add_password");
        add_password->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(add_password);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        add_password_again = new QLineEdit(layoutWidget1);
        add_password_again->setObjectName("add_password_again");
        add_password_again->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_4->addWidget(add_password_again);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        ask_number = new QLineEdit(layoutWidget1);
        ask_number->setObjectName("ask_number");

        horizontalLayout_5->addWidget(ask_number);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(registec);

        QMetaObject::connectSlotsByName(registec);
    } // setupUi

    void retranslateUi(QDialog *registec)
    {
        registec->setWindowTitle(QCoreApplication::translate("registec", "\346\263\250\345\206\214", nullptr));
        label_6->setText(QCoreApplication::translate("registec", "\344\273\223\345\272\223\347\256\241\347\220\206\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        btn_back_login->setText(QCoreApplication::translate("registec", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        btn_make_user->setText(QCoreApplication::translate("registec", "\347\241\256\345\256\232", nullptr));
        btn_exit1->setText(QCoreApplication::translate("registec", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("registec", "\347\224\250\346\210\267\345\220\215", nullptr));
        add_comment->setText(QCoreApplication::translate("registec", "\350\257\267\350\276\223\345\205\245\344\270\255\346\226\207\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("registec", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("registec", "\345\210\235\345\247\213\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("registec", "\345\206\215\346\254\241\350\276\223\345\205\245\345\210\235\345\247\213\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("registec", "\351\202\200\350\257\267\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registec: public Ui_registec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTEC_H
