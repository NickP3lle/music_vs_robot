#include "characterCell.h"

CharacterCell::CharacterCell(QWidget *parent) : QWidget(parent) { setStyleSheet("border: 1px solid black;"); }

void CharacterCell::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    QStyleOption StyleOpt;

    StyleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &StyleOpt, &painter, this);
}