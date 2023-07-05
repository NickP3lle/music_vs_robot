#include "cashWidget.h"

CashWidget::CashWidget(QWidget *parent)
    : QWidget(parent), label(new QLabel(this)) {
  Cash::registerObserver(this);

  Cash::add(1000);

  label->setFixedSize(100, 50);
  label->setAlignment(Qt::AlignCenter);

  updateCash();
}

void CashWidget::updateCash() { label->setText(QString::number(Cash::get())); }
