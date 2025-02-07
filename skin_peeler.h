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
    void onDayNightButtonClicked();  // �ۺ���������ť����¼�
signals:
    void changeBackgroundColor(const QColor &color);
private:
    Ui::skin_peeler *ui;
};

#endif // SKIN_PEELER_H
