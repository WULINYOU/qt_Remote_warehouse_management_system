#ifndef MANAGE_H
#define MANAGE_H

#include <QDialog>
#include <QSqlDatabase>
#include<QMessageBox>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include<QTimer>
#include<QDateTime>

namespace Ui {
class manage;
}

class manage : public QDialog
{
    Q_OBJECT

public:
   explicit manage(QWidget *parent = nullptr, const QString &comment = "");// 修改构造函数
    ~manage();
private slots:

void on_comboBox_currentIndexChanged();
void adjustColumnWidths();
void onExitButtonClicke();
 void loadData();
void onaddrecordButtonClicke();
 void onrefreshButtonClicke();
 void updateShowTimeLabel();
 void onupdatButtonclicke();
 void onStorageButtonClicke();
 void ondeleteButtonClicke();
 void onselectButtonClicke();
 void ondeleteTableButtonClicke();

 void onlessenButtonClicke();
 void onaddButtonClicke();
 void onselecttableButtonClikce();
 void onlogButtonClickee();
private:
    Ui::manage *ui;

private:
    QSqlDatabase db1;
    QLabel *time_label;
    QTimer *timer;
    QString m_comment;

};

#endif // MANAGE_H
