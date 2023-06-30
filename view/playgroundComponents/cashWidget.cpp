#include "cashWidget.h"

CashWidget::CashWidget(QWidget *parent) : QWidget(parent), cash(Cash::getInstance()), label(new QLabel(this)) {
    cash->registerObserver(this);

    label->setFixedSize(100, 50);
    label->setAlignment(Qt::AlignCenter);

    showCash();
}

void CashWidget::showCash() { label->setText(QString::number(cash->getTotal())); }

void CashWidget::updateCash() { showCash(); }