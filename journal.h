#ifndef JOURNAL_H
#define JOURNAL_H

#include <QDialog>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>
namespace Ui {
class journal;
}

class journal : public QDialog
{
    Q_OBJECT

public:
    explicit journal(QWidget *parent = nullptr);
    ~journal();
    void extracted();
    void logAction(const QString &username, const QString &action);

private:
    Ui::journal *ui;
    QSqlDatabase log_db;
    QSqlTableModel *model;

};

#endif // JOURNAL_H
