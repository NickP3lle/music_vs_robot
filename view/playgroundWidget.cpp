#include "playgroundWidget.h"

#include <QLabel>
#include <QPushButton>

PlaygroundWidget::PlaygroundWidget(QWidget *parent) : QWidget(parent), navBarLayout(new QHBoxLayout(this)) {

    QPushButton *backButton = new QPushButton("Back", this);
    QLabel *timer = new QLabel("Timer", this);
    QLabel *coins = new QLabel("Coins", this);

    backButton->setFixedSize(100, 50);
    timer->setFixedSize(100, 50);
    coins->setFixedSize(100, 50);

    // backButton->setStyleSheet("background-color: #ff0000; color: #ffffff; font-size: 20px; font-weight: bold;");
    timer->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");
    coins->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");

    timer->setAlignment(Qt::AlignCenter);
    coins->setAlignment(Qt::AlignCenter);

    connect(backButton, SIGNAL(clicked()), parent, SLOT(endGame()));

    navBarLayout->addWidget(backButton);
    navBarLayout->addWidget(timer);
    navBarLayout->addWidget(coins);

    navBarLayout->setAlignment(backButton, Qt::AlignLeft);
    navBarLayout->setAlignment(timer, Qt::AlignCenter);
    navBarLayout->setAlignment(coins, Qt::AlignRight);

    setLayout(navBarLayout);
}