#ifndef ADD_TABLE_H
#define ADD_TABLE_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class add_table;
}

class add_table : public QDialog
{
    Q_OBJECT

public:
    explicit add_table(QWidget *parent = nullptr, const QString &comment = "");
    ~add_table();
private slots:
    void addRow();
    void createTable();
   void clearAll();
    void exit();
private:
    Ui::add_table *ui;
    QSqlDatabase db8;
    journal *m_journal;
    QString m_comment;
};

#endif // ADD_TABLE_H
