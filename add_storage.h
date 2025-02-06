#ifndef ADD_STORAGE_H
#define ADD_STORAGE_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class add_Storage;
}

class add_Storage : public QDialog
{
    Q_OBJECT

public:
    explicit add_Storage(QWidget *parent = nullptr, const QString &comment = "");

    ~add_Storage();
private slots:


   void on_Storage_oldok_clicked();
    bool validatePositiveInteger(const QString &input, int &output);
    void on_Storage_exit_clicked();
private:
    Ui::add_Storage *ui;
    QSqlDatabase db4;
    journal *m_journal;
    QString m_comment;
};

#endif // ADD_STORAGE_H
