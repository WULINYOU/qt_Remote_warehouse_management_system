#ifndef ADD_RECORD_H
#define ADD_RECORD_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class add_record;
}

class add_record : public QDialog
{
    Q_OBJECT

public:
    explicit add_record(QWidget *parent = nullptr);
    ~add_record();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_backmanage();
private:
    Ui::add_record *ui;
    QSqlDatabase db2;

};

#endif // ADD_RECORD_H
