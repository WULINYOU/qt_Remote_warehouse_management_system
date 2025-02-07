#include "skin_peeler.h"
#include "ui_skin_peeler.h"

skin_peeler::skin_peeler(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::skin_peeler)
{
    ui->setupUi(this);

    // 连接按钮的点击事件到槽函数
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
        this->setStyleSheet("background-color: white;");  // 直接在此处设置样式表
        emit changeBackgroundColor(Qt::white);  // 同时通知其他监听者
    } else if (ui->black->isChecked()) {
        qDebug() << "Night mode selected";
        this->setStyleSheet("background-color: gray;");  // 使用更常见的灰色表示夜间模式
        emit changeBackgroundColor(QColor(128, 128, 128));  // 同时通知其他监听者
    }
}

