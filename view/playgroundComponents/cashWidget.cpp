#include "cashWidget.h"

CashWidget::CashWidget(QWidget *parent) : QWidget(parent), label(new QLabel(this)) {
    Cash::getInstance()->addObserver(this);

    label->setFixedSize(100, 50);
    label->setAlignment(Qt::AlignCenter);

    update(Cash::getInstance());
}

void CashWidget::update(const Cash *c) { label->setText(QString::number(c->Cash::get())); }
