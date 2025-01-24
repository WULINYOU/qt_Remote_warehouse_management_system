#ifndef ADD_STORAGE_H
#define ADD_STORAGE_H

#include <QDialog>
#include<QSqlDatabase>

namespace Ui {
class add_Storage;
}

class add_Storage : public QDialog
{
    Q_OBJECT

public:
    explicit add_Storage(QWidget *parent = nullptr);
    ~add_Storage();
private slots:


   void on_Storage_oldok_clicked(bool checked);
    bool validatePositiveInteger(const QString &input, int &output);

private:
    Ui::add_Storage *ui;
    QSqlDatabase db4;

};

#endif // ADD_STORAGE_H
