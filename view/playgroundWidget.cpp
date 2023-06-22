#include "playgroundWidget.h"

#include <QGridLayout>
#include <QVBoxLayout>

PlaygroundWidget::PlaygroundWidget(QWidget *parent)
    : QWidget(parent), backButton(new QPushButton("Back", this)), timerLabel(new QLabel(this)), coins(new QLabel(this)),
      timer(new QTimer(this)) {

    timerLabel->setText("00:00");
    coins->setText("0");
    timer->setInterval(1000);

    backButton->setFixedSize(100, 60);
    timerLabel->setFixedSize(100, 50);
    coins->setFixedSize(100, 50);

    // backButton->setStyleSheet("background-color: #ff0000; color: #ffffff; font-size: 20px; font-weight: bold;");
    timerLabel->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");
    coins->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");

    timerLabel->setAlignment(Qt::AlignCenter);
    coins->setAlignment(Qt::AlignCenter);

    connect(backButton, SIGNAL(clicked()), parent, SLOT(endGame()));
    connect(backButton, &QPushButton::clicked, this, [this] { updateTimerLabel(true); });
    connect(parent, SIGNAL(startTimer()), this, SLOT(startTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerLabel()));

    QHBoxLayout *navBarLayout = new QHBoxLayout();

    navBarLayout->addWidget(backButton);
    navBarLayout->addWidget(timerLabel);
    navBarLayout->addWidget(coins);

    navBarLayout->setAlignment(backButton, Qt::AlignLeft);
    navBarLayout->setAlignment(timerLabel, Qt::AlignCenter);
    navBarLayout->setAlignment(coins, Qt::AlignRight);

    QPushButton *violinButton = new QPushButton("Violin", this);
    QPushButton *trumpetButton = new QPushButton("Trumpet", this);
    QPushButton *drumButton = new QPushButton("Drum", this);
    QPushButton *saxophoneButton = new QPushButton("Saxophone", this);
    QPushButton *fluteButton = new QPushButton("Flute", this);
    QPushButton *removeButton = new QPushButton("Remove", this);

    violinButton->setFixedSize(100, 50);
    trumpetButton->setFixedSize(100, 50);
    drumButton->setFixedSize(100, 50);
    saxophoneButton->setFixedSize(100, 50);
    fluteButton->setFixedSize(100, 50);
    removeButton->setFixedSize(100, 60);

    QVBoxLayout *sideBarLayout = new QVBoxLayout();

    sideBarLayout->addWidget(violinButton);
    sideBarLayout->addWidget(trumpetButton);
    sideBarLayout->addWidget(drumButton);
    sideBarLayout->addWidget(saxophoneButton);
    sideBarLayout->addWidget(fluteButton);
    sideBarLayout->addWidget(removeButton);

    sideBarLayout->setAlignment(removeButton, Qt::AlignBottom);

    QGridLayout *gridLayout = new QGridLayout();

    // Set the grid line style
    gridLayout->setHorizontalSpacing(1);
    gridLayout->setVerticalSpacing(1);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    const int rows = 5;
    const int columns = 11;

    // Create empty cells in the grid
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            QWidget *cell = new QWidget();

            if (column == columns - 1) {
                cell->setStyleSheet("background-color: #3d3d3d; border: 1px solid black;");
            } else {
                cell->setStyleSheet("border: 1px solid black;"); // Display grid lines
            }

            gridLayout->addWidget(cell, row, column);
        }
    }

    QHBoxLayout *sidebar_gridLayout = new QHBoxLayout();

    sidebar_gridLayout->addLayout(sideBarLayout);
    sidebar_gridLayout->addLayout(gridLayout);

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->addLayout(navBarLayout);
    vBoxLayout->addLayout(sidebar_gridLayout);

    setLayout(vBoxLayout);
}

void PlaygroundWidget::updateTimerLabel(bool reset) {
    static int elapsedTime = 0;

    if (reset) {
        elapsedTime = 0;
        timer->stop();
        timerLabel->setText("00:00");
        return;
    }

    elapsedTime++;
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;

    QString elapsedTimeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    timerLabel->setText(elapsedTimeString);

    // qDebug() << "updateTimerLabel()";
}

void PlaygroundWidget::startTimer() { timer->start(); }