#ifndef TIMER_WIDGET_H
#define TIMER_WIDGET_H

#include "../../game/include.h"
#include "../../game/timer.h"
#include "../observers/timerObserverInterface.h"
#include <QLabel>
#include <QWidget>

class TimerWidget : public QWidget, public TimerObserverInterface {
  Q_OBJECT

private:
  QLabel *label;

public:
  TimerWidget(QWidget *parent = 0);
  void updateTimer() override;
  void setAlignment(Qt::AlignmentFlag alignment) {
    label->setAlignment(alignment);
  }
  void setText(QString text) { label->setText(text); }
};

#endif
