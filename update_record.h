#ifndef UPDATE_RECORD_H
#define UPDATE_RECORD_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class update_record;
}

class update_record : public QDialog
{
    Q_OBJECT

public:
    explicit update_record(QWidget *parent = nullptr, const QString &comment = "");
    ~update_record();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_updateButtonClicked();
    void exitButtonClicked();



private:
    Ui::update_record *ui;
    QSqlDatabase db3;
    journal *m_journal;
    QString m_comment;

};

#endif // UPDATE_RECORD_H
