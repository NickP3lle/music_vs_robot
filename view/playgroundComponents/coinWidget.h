#ifndef COIN_WIDGET_H
#define COIN_WIDGET_H

#include "../../game/cash.h"
#include "../../game/include.h"
#include <QLabel>
// #include <QPixmap>
#include <QWidget>

class CoinWidget : public QWidget {
    Q_OBJECT

  private:
    Cash *cash;
    QLabel *label;
    // QPixmap *pixmap;

  public:
    CoinWidget(QWidget *parent = 0);
    // void setPixmap(CoinType type);
    void showCoin();
};

#endif