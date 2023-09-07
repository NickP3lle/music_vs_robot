#ifndef CASH_WIDGET_H
#define CASH_WIDGET_H

#include "../../include.h"
#include "../../playground/cash.h"
#include <QLabel>
// #include <QPixmap>
#include <QWidget>

class CashWidget : public QWidget, public ObserverInterface<Cash> {
    Q_OBJECT

  private:
    QLabel *label;

  public:
    CashWidget(QWidget *parent = 0);
    void update(const Cash *c) override;
};

#endif
