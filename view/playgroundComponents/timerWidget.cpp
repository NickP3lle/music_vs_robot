#include "timerWidget.h"

TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent), label(new QLabel(this)) {
    label->setFixedSize(100, 50);
    Timer::start();
    Timer::getInstance()->addObserver(this);
    label->setAlignment(Qt::AlignCenter);
    update(Timer::getInstance());
}

void TimerWidget::update(const Timer *t) {
    QString elapsedTimeString =
        QString("%1:%2").arg(t->Timer::minutes(), 2, 10, QChar('0')).arg(t->Timer::seconds(), 2, 10, QChar('0'));
    label->setText(elapsedTimeString);
}
