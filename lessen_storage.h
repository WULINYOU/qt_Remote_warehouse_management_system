#ifndef LESSEN_STORAGE_H
#define LESSEN_STORAGE_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class lessen_storage;
}

class lessen_storage : public QDialog
{
    Q_OBJECT

public:
    explicit lessen_storage(QWidget *parent = nullptr, const QString &comment = "");
    ~lessen_storage();
private slots:
    void on_lessen_storage_clicked();
    bool validatePositiveInteger(const QString &input, int &output);
    void on_lessen_storage_exit_clicked();
private:
    Ui::lessen_storage *ui;
    QSqlDatabase db5;
    journal *m_journal;
    QString m_comment;
};

#endif // LESSEN_STORAGE_H
