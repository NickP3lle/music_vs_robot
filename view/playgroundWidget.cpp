#include "playgroundWidget.h"

#include "visitors/imageVisitor.h"

#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>

PlaygroundWidget::PlaygroundWidget(QWidget *parent)
    : QWidget(parent), backButton(new QPushButton("Back", this)), timerLabel(new QLabel(this)), cash(new CashWidget(this)),
      timer(new QTimer(this)), violinButton(new InstrumentButton(new Violin(), "Violin", this)),
      trumpetButton(new InstrumentButton(new Trumpet(), "Trumpet", this)),
      drumButton(new InstrumentButton(new Drum(), "Drum", this)),
      saxophoneButton(new InstrumentButton(new Saxophone(), "Saxophone", this)),
      fluteButton(new InstrumentButton(new Flute(), "Flute", this)), removeButton(new QPushButton("Remove", this)) {

    // playground->registerObserver(this);
    Playground::registerObserver(this);

    /// Navigation bar
    timerLabel->setText("00:00");
    timer->setInterval(1000);

    backButton->setFixedSize(100, 60);
    timerLabel->setFixedSize(100, 50);
    cash->setFixedSize(100, 50);

    // backButton->setStyleSheet("background-color: #ff0000; color: #ffffff; font-size: 20px; font-weight: bold;");
    timerLabel->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");
    cash->setStyleSheet("background-color: #000000; color: #ffffff; font-size: 20px; font-weight: bold;");

    timerLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout *navBarLayout = new QHBoxLayout();

    navBarLayout->addWidget(backButton);
    navBarLayout->addWidget(timerLabel);
    navBarLayout->addWidget(cash);

    navBarLayout->setAlignment(backButton, Qt::AlignLeft);
    navBarLayout->setAlignment(timerLabel, Qt::AlignCenter);
    navBarLayout->setAlignment(cash, Qt::AlignRight);

    /// When the back button is clicked, the timer is stopped
    connect(backButton, &QPushButton::clicked, this, [this] { updateTimerLabel(true); });

    connect(parent, SIGNAL(startTimer()), this, SLOT(startTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerLabel()));
    connect(backButton, SIGNAL(clicked()), parent, SLOT(endGame()));

    /// Side bar
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

    /// Grid
    QGridLayout *gridLayout = new QGridLayout();

    gridLayout->setHorizontalSpacing(1);
    gridLayout->setVerticalSpacing(1);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS; ++col) {
            cells[row][col] = new PlaygroundCellWidget(this);
            if (col == COLUMNS - 1) {
                cells[row][col]->setStyleSheet("background-color: #3d3d3d; border: 1px solid black;");
            }

            gridLayout->addWidget(cells[row][col], row, col);

            connect(cells[row][col], &PlaygroundCellWidget::clicked, this, [this, row, col] { insertEntity(row, col); });
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

void PlaygroundWidget::insertEntity(int row, int col) {
    MusicInstruments *m = InstrumentButton::getSelectedInstrument();

    if (!m) {
        qDebug() << "No instrument selected!";
        return;
    }

    if (col == COLUMNS - 1) {
        qDebug() << "Cannot insert entity in the last column!";
        return;
    }

    // if (playground->playerInsert(row, col, m)) {
    if (Playground::getInstance()->playerInsert(row, col, m)) {
        qDebug() << "Player inserted entity!";
    } else {
        qDebug() << "Player cannot insert entity!";
        return;
    }

    InstrumentButton::removeSelectedInstrument();
}

void PlaygroundWidget::updatePlayground(Entity *entity) {
    for (u32 row = 0; row < ROWS; row++) {
        for (u32 col = 0; col < COLUMNS; col++) {
            if (entity) {
                MusicInstruments *mi = dynamic_cast<MusicInstruments *>(entity);
                if (mi) {
                    updatePlaygroundMusic(row, col, mi);
                } else {
                    updatePlaygroundRobot(row, col, dynamic_cast<Robot *>(entity));
                }
            } else {
                updatePlaygroundMusic(row, col);
                updatePlaygroundRobot(row, col);
            }
        }
    }
}

void PlaygroundWidget::updatePlaygroundMusic(u32 row, u32 col, MusicInstruments *mi) {
    if (mi) {
        /// Vistor sets the image of the cell
        imageVisitor iv;
        mi->accept(iv);
        cells[row][col]->setImage(iv.getPixmap());
    } else {
        cells[row][col]->setImage(new QPixmap());
    }
}

void PlaygroundWidget::updatePlaygroundRobot(u32 row, u32 col, Robot *r) {
    if (r) {
        /// Vistor sets the image of the cell
        imageVisitor iv;
        r->accept(iv);
        cells[row][col]->setImage(iv.getPixmap());
    } else {
        cells[row][col]->setImage(new QPixmap());
    }
}