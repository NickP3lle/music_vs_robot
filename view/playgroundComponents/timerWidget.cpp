#include "timerWidget.h"

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent), label(new QLabel(this)) {
  Timer::start();
  Timer::registerObserver(this);
  label->setAlignment(Qt::AlignCenter);
  updateTimer();
}

void TimerWidget::updateTimer() {

  QString elapsedTimeString = QString("%1:%2")
                                  .arg(Timer::minutes(), 2, 10, QChar('0'))
                                  .arg(Timer::seconds(), 2, 10, QChar('0'));
  label->setText(elapsedTimeString);
}
