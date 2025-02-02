#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"journal.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//000
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onExitButtonClicked();
    void onLoginButtonClicked();
    void onRegisterButtonClicked();
private:
    Ui::MainWindow *ui;
    QString comment;
    journal *m_journal;
};
#endif // MAINWINDOW_H
