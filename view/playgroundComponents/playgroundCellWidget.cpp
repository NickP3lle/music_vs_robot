#include "playgroundCellWidget.h"

void PlaygroundCellWidget::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    emit clicked();
}

PlaygroundCellWidget::PlaygroundCellWidget(QWidget *parent) : QWidget(parent) { setStyleSheet("border: 1px solid black;"); }

void PlaygroundCellWidget::setImage(QPixmap *pmap) {
    pixmap = pmap;
    // update();
}

void PlaygroundCellWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    QStyleOption StyleOpt;

    StyleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &StyleOpt, &painter, this);
}