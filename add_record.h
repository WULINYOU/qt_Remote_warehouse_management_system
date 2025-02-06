#ifndef ADD_RECORD_H
#define ADD_RECORD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QTimer>
#include"journal.h"
namespace Ui {
class add_record;
}

class add_record : public QDialog
{
    Q_OBJECT

public:
    explicit add_record(QWidget *parent = nullptr, const QString &comment = "");
    ~add_record();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_backmanage();
    void updateShowTimeLabel();
    void showTimetable(int row,int col);
    void initializeDateTimePickers(int row);
    void showDateTimePicker(int row, int col);
    void add_okButtonClicked();

private:
    Ui::add_record *ui;
    QSqlDatabase db2;
     QSqlDatabase db1;
    QTimer *timer;
     journal *m_journal;
    QString m_comment;
};

#endif // ADD_RECORD_H
