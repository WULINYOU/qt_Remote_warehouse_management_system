#ifndef SELECT_TABLE_H
#define SELECT_TABLE_H

#include <QDialog>
#include<QSqlDatabase>
namespace Ui {
class select_table;
}

class select_table : public QDialog
{
    Q_OBJECT

public:
    explicit select_table(QWidget *parent = nullptr);
    ~select_table();
private slots:
    void onselectButtonClick();
    void onExitButtonClicke();

private:
    Ui::select_table *ui;
    QSqlDatabase db10;

};

#endif // SELECT_TABLE_H
