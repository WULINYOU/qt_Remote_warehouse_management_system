#ifndef DELETE_RECORD_H
#define DELETE_RECORD_H

#include <QDialog>
#include<QSqlDatabase>
namespace Ui {
class delete_record;
}

class delete_record : public QDialog
{
    Q_OBJECT

public:
    explicit delete_record(QWidget *parent = nullptr);
    ~delete_record();
private slots:
    void onfirst_sureButtonClicke();
    void onexitButtonClicke();

private:
    Ui::delete_record *ui;
    QSqlDatabase db6;
};

#endif // DELETE_RECORD_H
