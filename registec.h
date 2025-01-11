#ifndef REGISTEC_H
#define REGISTEC_H

#include <QDialog>

#include <QSqlDatabase>
namespace Ui {
class registec;
}

class registec : public QDialog
{
    Q_OBJECT

public:
    explicit registec(QWidget *parent = nullptr);
    ~registec();
private slots:
    void onMakeUserButtonClicked();
    void onBackloginButtonClicked();
    void onExitButtonClicked();

private:
    Ui::registec *ui;
    QSqlDatabase db;
};

#endif // REGISTEC_H
