#ifndef SKIN_PEELER_H
#define SKIN_PEELER_H

#include <QDialog>

namespace Ui {
class skin_peeler;
}

class skin_peeler : public QDialog
{
    Q_OBJECT

public:
    explicit skin_peeler(QWidget *parent = nullptr);
    ~skin_peeler();

private slots:
    void onDayNightButtonClicked();  // 槽函数：处理按钮点击事件
signals:
    void changeBackgroundColor(const QColor &color);
private:
    Ui::skin_peeler *ui;
};

#endif // SKIN_PEELER_H
