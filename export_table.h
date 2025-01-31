#ifndef EXPORT_TABLE_H
#define EXPORT_TABLE_H

#include <QDialog>
#include<QSqlDatabase>
namespace Ui {
class export_table;
}

class export_table : public QDialog
{
    Q_OBJECT

public:
    explicit export_table(QWidget *parent = nullptr);
    ~export_table();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    //void onexport_okButtonClicke();
private:
    Ui::export_table *ui;
    QSqlDatabase db10;
};

#endif // EXPORT_TABLE_H
