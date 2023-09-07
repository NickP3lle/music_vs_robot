#include "playgroundCellWidget.h"

#include <QHBoxLayout>

void PlaygroundCellWidget::mousePressEvent(QMouseEvent *event) {
    std::cout << "PlaygroundCellWidget::mousePressEvent" << std::endl;
    QWidget::mousePressEvent(event);
    emit clicked();
}

PlaygroundCellWidget::PlaygroundCellWidget(QWidget *parent)
    : QWidget(parent), leveleLabel(new QLabel(this)), pixmapLabel(new QLabel(this)) {

    leveleLabel->setAlignment(Qt::AlignCenter);
    // leveleLabel->setText("0");
    leveleLabel->hide();
    setStyleSheet("border: 1px solid black;");
    pixmapLabel->setAlignment(Qt::AlignCenter);
    pixmapLabel->setStyleSheet("border: 0;");

    setLayout(new QHBoxLayout(this));
    layout()->addWidget(pixmapLabel);
    layout()->setContentsMargins(0, 0, 0, 0);

    pixmapLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void PlaygroundCellWidget::setImage(QPixmap *pixmap) { pixmapLabel->setPixmap(*pixmap); }

void PlaygroundCellWidget::setLevel(u32 level) {
    leveleLabel->setText(QString::number(level));
    leveleLabel->show();
}

void PlaygroundCellWidget::hideLevel() { leveleLabel->hide(); }

void PlaygroundCellWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    QStyleOption StyleOpt;

    StyleOpt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_Widget, &StyleOpt, &painter, this);
}