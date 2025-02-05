#ifndef SELECT_RECORD_H
#define SELECT_RECORD_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class select_record;
}

class select_record : public QDialog
{
    Q_OBJECT

public:
    explicit select_record(QWidget *parent = nullptr, const QString &comment = "");
    ~select_record();
private slots:

    void on_comboBox_currentIndexChanged(int index);
    void on_exitButtonClicke();
    void on_selectButtonClicke();
private:
    Ui::select_record *ui;
    QSqlDatabase db7;
    journal *m_journal;
    QString m_comment;

};

#endif // SELECT_RECORD_H
