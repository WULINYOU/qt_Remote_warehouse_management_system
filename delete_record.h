#ifndef DELETE_RECORD_H
#define DELETE_RECORD_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class delete_record;
}

class delete_record : public QDialog
{
    Q_OBJECT

public:
    explicit delete_record(QWidget *parent = nullptr, const QString &comment = "");
    ~delete_record();
private slots:
    void onfirst_sureButtonClicke();
    void onexitButtonClicke();

private:
    Ui::delete_record *ui;
    QSqlDatabase db6;
    journal *m_journal;
    QString m_comment;
};

#endif // DELETE_RECORD_H
