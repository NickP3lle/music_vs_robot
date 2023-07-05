#include "timerWidget.h"

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent), label(new QLabel(this)) {
  label->setAlignment(Qt::AlignCenter);
  label->setStyleSheet("QLabel { color: white; }");
  label->setFont(QFont("Courier", 20, QFont::Bold));
  label->setGeometry(0, 0, 100, 50);
}

void TimerWidget::updateTimer() {
  label->setText(QString::number(Timer::get()));
}
