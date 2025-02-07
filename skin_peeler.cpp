#include "skin_peeler.h"
#include "ui_skin_peeler.h"

skin_peeler::skin_peeler(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::skin_peeler)
{
    ui->setupUi(this);

    // ���Ӱ�ť�ĵ���¼����ۺ���
    connect(ui->write, &QRadioButton::clicked, this, &skin_peeler::onDayNightButtonClicked);
    connect(ui->black, &QRadioButton::clicked, this, &skin_peeler::onDayNightButtonClicked);
}

skin_peeler::~skin_peeler()
{
    delete ui;
}

void skin_peeler::onDayNightButtonClicked()
{
    if (ui->write->isChecked()) {
        qDebug() << "Day mode selected";
        this->setStyleSheet("background-color: white;");  // ֱ���ڴ˴�������ʽ��
        emit changeBackgroundColor(Qt::white);  // ͬʱ֪ͨ����������
    } else if (ui->black->isChecked()) {
        qDebug() << "Night mode selected";
        this->setStyleSheet("background-color: gray;");  // ʹ�ø������Ļ�ɫ��ʾҹ��ģʽ
        emit changeBackgroundColor(QColor(128, 128, 128));  // ͬʱ֪ͨ����������
    }
}

