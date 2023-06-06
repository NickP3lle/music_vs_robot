#include "playgroundWidget.h"

#include <QLabel>
#include <QPushButton>

PlaygroundWidget::PlaygroundWidget(QWidget *parent) : QWidget(parent) {
    QLabel *title = new QLabel("Playground", this);
    QPushButton *backButton = new QPushButton("Back", this);
}