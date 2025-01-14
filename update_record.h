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
    void loadData();
    void on_comboBox_currentIndexChanged(int index);
void initializeDateTimePickers(int row);
   // void showTimetable(int row, int col);
    void showDateTimePicker(int row, int col);
    void on_updateButtonClicked();
    void exitButtonClicked();



private:
    Ui::update_record *ui;
private:
    QSqlDatabase db3;

};

#endif // UPDATE_RECORD_H
