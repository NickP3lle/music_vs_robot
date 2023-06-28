#include "coinWidget.h"

CoinWidget::CoinWidget(QWidget *parent) : QWidget(parent), cash(Cash::getInstance()), label(new QLabel(this)) {
    // label->setPixmap(QPixmap(":/images/coin.png"));
    label->setFixedSize(100, 50);
    label->setAlignment(Qt::AlignCenter);

    showCoin();
}

void CoinWidget::showCoin() { label->setText(QString::number(cash->getTotal())); }