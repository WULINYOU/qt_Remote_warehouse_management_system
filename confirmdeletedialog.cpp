#include "ConfirmDeleteDialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

ConfirmDeleteDialog::ConfirmDeleteDialog(QWidget *parent)
    : QDialog(parent), countdownSeconds(10) {
    setWindowTitle("确认删除");

    QVBoxLayout *layout = new QVBoxLayout(this);

    countdownLabel = new QLabel("请在10秒内确认删除", this);
    layout->addWidget(countdownLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    cancelButton = new QPushButton("取消", this);
    confirmButton = new QPushButton("确定", this);
    confirmButton->setEnabled(false); // 初始状态下禁用确定按钮

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(confirmButton);
    layout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, this, &ConfirmDeleteDialog::onCanceled);
    connect(confirmButton, &QPushButton::clicked, this, &ConfirmDeleteDialog::onConfirmed);

    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, [this]() {
        if (countdownSeconds > 0) {
            countdownSeconds--;
            updateCountdown(countdownSeconds);
        } else {
            confirmButton->setEnabled(true);
            countdownTimer->stop();
        }
    });

    startCountdown();
}

void ConfirmDeleteDialog::startCountdown() {
    countdownSeconds = 10;
    updateCountdown(countdownSeconds);
    countdownTimer->start(1000); // 每秒触发一次
}

void ConfirmDeleteDialog::updateCountdown(int remaining) {
    countdownLabel->setText(QString("请在 %1 秒内确认删除").arg(remaining));
}

void ConfirmDeleteDialog::onCanceled() {
    emit canceled();
    reject(); // 关闭对话框并返回拒绝结果
}

void ConfirmDeleteDialog::onConfirmed() {
    emit confirmed();
    accept(); // 关闭对话框并返回接受结果
}
