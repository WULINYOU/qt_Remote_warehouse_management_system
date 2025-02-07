#ifndef MANAGE_H
#define MANAGE_H

#include <QDialog>
#include <QSqlDatabase>
#include<QMessageBox>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include<QTimer>
#include<QDateTime>
#include<skin_peeler.h>
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
 void onskinpeelerButtonClicke();
void changeBackground(const QColor &color);
private:
    Ui::manage *ui;

private:
    QSqlDatabase db1;
    QLabel *time_label;
    QTimer *timer;
    QString m_comment;
    skin_peeler *peeler;

};

#endif // MANAGE_H
