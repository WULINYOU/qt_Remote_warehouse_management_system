#ifndef UPDATE_RECORD_H
#define UPDATE_RECORD_H

#include <QDialog>
#include<QSqlDatabase>

namespace Ui {
class update_record;
}

class update_record : public QDialog
{
    Q_OBJECT

public:
    explicit update_record(QWidget *parent = nullptr);
    ~update_record();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_updateButtonClicked();
    void exitButtonClicked();
    //void on_table_element_currentIndexChanged(int index);

private:
    Ui::update_record *ui;
    QSqlDatabase db3;

};

#endif // UPDATE_RECORD_H
