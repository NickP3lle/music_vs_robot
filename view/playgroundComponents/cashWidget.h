#ifndef CASH_WIDGET_H
#define CASH_WIDGET_H

#include "../../game/cash.h"
#include "../../game/include.h"
#include "../observers/cashObserverInterface.h"
#include <QLabel>
// #include <QPixmap>
#include <QWidget>

class CashWidget : public QWidget, public CashObserverInterface {
    Q_OBJECT

  private:
    Cash *cash;
    QLabel *label;

  public:
    CashWidget(QWidget *parent = 0);
    void showCash();

    void updateCash() override;
};

#endif