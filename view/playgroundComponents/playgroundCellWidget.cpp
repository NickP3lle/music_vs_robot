#include "playgroundCellWidget.h"

#include <QHBoxLayout>

void PlaygroundCellWidget::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    emit clicked();
}

PlaygroundCellWidget::PlaygroundCellWidget(QWidget *parent)
    : QWidget(parent), occupied(false), pixmapLabel(new QLabel(this)) {
    setStyleSheet("border: 1px solid black;");
    pixmapLabel->setAlignment(Qt::AlignCenter);
    pixmapLabel->setStyleSheet("border: 0;");

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(pixmapLabel);
    layout()->setContentsMargins(0, 0, 0, 0);

    pixmapLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

bool PlaygroundCellWidget::isOccupied() const { return occupied; }

void PlaygroundCellWidget::setImage(QPixmap *pixmap) { pixmapLabel->setPixmap(*pixmap); }

void PlaygroundCellWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    QStyleOption StyleOpt;

    StyleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &StyleOpt, &painter, this);
}