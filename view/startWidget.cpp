#include "startWidget.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

StartWidget::StartWidget(QWidget *parent) : QWidget(parent) {
    QLabel *title = new QLabel("Music vs Robots", this);
    QPushButton *startButton = new QPushButton("New Game", this);
    QPushButton *loadButton = new QPushButton("Load Game", this);
    QPushButton *quitButton = new QPushButton("Quit", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(startButton);
    layout->addWidget(loadButton);
    layout->addWidget(quitButton);
    setLayout(layout);
}