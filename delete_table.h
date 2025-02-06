#ifndef DELETE_TABLE_H
#define DELETE_TABLE_H

#include <QDialog>
#include<QSqlDatabase>
#include"journal.h"
namespace Ui {
class delete_table;
}

class delete_table : public QDialog
{
    Q_OBJECT

public:
    explicit delete_table(QWidget *parent = nullptr, const QString &comment = "");
    ~delete_table();
private slots:
   void on_comboBox_currentIndexChanged(int index);
    void on_deleta_table_ButtonClicke();
private:
    Ui::delete_table *ui;
    QSqlDatabase db9;
    journal *m_journal;
    QString m_comment;
};

#endif // DELETE_TABLE_H
