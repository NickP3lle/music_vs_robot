#include "cashWidget.h"

CashWidget::CashWidget(QWidget *parent) : QWidget(parent), label(new QLabel(this)) {
    Cash::registerObserver(this);

    label->setFixedSize(100, 50);
    label->setAlignment(Qt::AlignCenter);

    showCash();
}

void CashWidget::showCash() { label->setText(QString::number(Cash::getInstance()->getTotal())); }

void CashWidget::updateCash() { showCash(); }