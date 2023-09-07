#ifndef TIMER_WIDGET_H
#define TIMER_WIDGET_H

#include "../../include.h"
#include "../../playground/timer.h"
#include <QLabel>
#include <QWidget>

class TimerWidget : public QWidget, public ObserverInterface<Timer> {
    Q_OBJECT

  private:
    QLabel *label;

  public:
    TimerWidget(QWidget *parent = 0);
    void update(const Timer *t) override;
};
#endif
