#include "startWidget.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QScreen>
#include <QSpacerItem>
#include <QVBoxLayout>

StartWidget::StartWidget(QWidget *parent) : QWidget(parent) {
    QLabel *title = new QLabel("Music vs Robots", this);
    QPushButton *startButton = new QPushButton("New Game", this);
    QPushButton *loadButton = new QPushButton("Load Game", this);
    QPushButton *quitButton = new QPushButton("Quit", this);

    QSpacerItem *topSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem *bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    title->setStyleSheet("color: white; font-size: 70px; font-weight: "
                         "bold; text-align: center;");
    title->setAlignment(Qt::AlignCenter);
    // title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    startButton->setStyleSheet("padding: 10px; color: white; font-size: 30px;");
    loadButton->setStyleSheet("padding: 10px; color: white; font-size: 30px;");
    quitButton->setStyleSheet("padding: 10px; color: white; font-size: 30px;");

    title->setFixedSize(600, 150);
    startButton->setFixedSize(220, 50);
    loadButton->setFixedSize(220, 50);
    quitButton->setFixedSize(220, 50);

    connect(quitButton, SIGNAL(clicked()), parent, SLOT(close()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addItem(topSpacer);
    layout->addWidget(title);
    layout->addWidget(startButton);
    layout->addWidget(loadButton);
    layout->addWidget(quitButton);
    layout->addItem(bottomSpacer);

    layout->setAlignment(title, Qt::AlignCenter);
    layout->setAlignment(startButton, Qt::AlignCenter);
    layout->setAlignment(loadButton, Qt::AlignCenter);
    layout->setAlignment(quitButton, Qt::AlignCenter);

    setLayout(layout);
}