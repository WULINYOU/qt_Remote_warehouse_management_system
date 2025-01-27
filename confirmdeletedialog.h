#ifndef CONFIRMDELETEDIALOG_H
#define CONFIRMDELETEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class ConfirmDeleteDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConfirmDeleteDialog(QWidget *parent = nullptr);

signals:
    void confirmed();
    void canceled();

private slots:
    void startCountdown();
    void updateCountdown(int remaining);
    void onCanceled();
    void onConfirmed();

private:
    QLabel *countdownLabel;
    QPushButton *cancelButton;
    QPushButton *confirmButton;
    QTimer *countdownTimer;
    int countdownSeconds;
};

#endif // CONFIRMDELETEDIALOG_H
