#include "playgroundWidget.h"

#include "visitors/imageVisitor.h"

#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>

PlaygroundWidget::PlaygroundWidget(QWidget *parent)
    : QWidget(parent), backButton(new QPushButton("Back", this)), cash(new CashWidget(this)), timer(new TimerWidget(this)),
      violinButton(new InstrumentButton(new Violin(), "Violin", this)),
      trumpetButton(new InstrumentButton(new Trumpet(), "Trumpet", this)),
      drumButton(new InstrumentButton(new Drum(), "Drum", this)),
      saxophoneButton(new InstrumentButton(new Saxophone(), "Saxophone", this)),
      fluteButton(new InstrumentButton(new Flute(), "Flute", this)), levelUpButton(new QPushButton("Level Up", this)),
      removeButton(new QPushButton("Remove", this)), hasFocus({-1, -1}) {

    // playground->registerObserver(this);
    Playground::registerObserver(this);

    /// Navigation bar
    backButton->setFixedSize(100, 60);
    timer->setFixedSize(100, 50);
    cash->setFixedSize(100, 50);

    // backButton->setStyleSheet("background-color: #ff0000; color: #ffffff;
    // font-size: 20px; font-weight: bold;");
    timer->setStyleSheet("background-color: #000000; color: #ffffff; "
                         "font-size: 20px; font-weight: bold;");
    cash->setStyleSheet("background-color: #000000; color: #ffffff; font-size: "
                        "20px; font-weight: bold;");

    QHBoxLayout *navBarLayout = new QHBoxLayout();

    navBarLayout->addWidget(backButton);
    navBarLayout->addWidget(timer);
    navBarLayout->addWidget(cash);

    navBarLayout->setAlignment(backButton, Qt::AlignLeft);
    navBarLayout->setAlignment(timer, Qt::AlignCenter);
    navBarLayout->setAlignment(cash, Qt::AlignRight);

    /// When the back button is clicked, the timer is stopped
    connect(backButton, SIGNAL(clicked()), parent, SLOT(endGame()));

    /// Side bar
    violinButton->setFixedSize(100, 50);
    trumpetButton->setFixedSize(100, 50);
    drumButton->setFixedSize(100, 50);
    saxophoneButton->setFixedSize(100, 50);
    fluteButton->setFixedSize(100, 50);
    levelUpButton->setFixedSize(100, 60);
    removeButton->setFixedSize(100, 60);

    QVBoxLayout *sideBarLayout = new QVBoxLayout();

    sideBarLayout->addWidget(violinButton);
    sideBarLayout->addWidget(trumpetButton);
    sideBarLayout->addWidget(drumButton);
    sideBarLayout->addWidget(saxophoneButton);
    sideBarLayout->addWidget(fluteButton);
    sideBarLayout->addWidget(levelUpButton);
    sideBarLayout->addWidget(removeButton);

    sideBarLayout->setAlignment(levelUpButton, Qt::AlignBottom);
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

            connect(cells[row][col], &PlaygroundCellWidget::clicked, this, [this, row, col] {
                setFocus(row, col);
                insertEntity(row, col);
            });
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

void PlaygroundWidget::insertEntity(u32 row, u32 col) {
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

void PlaygroundWidget::clearPlayground() {
    for (u32 row = 0; row < ROWS; row++) {
        for (u32 col = 0; col < COLUMNS; col++) {
            updatePlaygroundMusic(row, col);
            std::cout << "clearPlayground" << std::endl;
            updatePlaygroundRobot(row, col);
        }
    }
}

void PlaygroundWidget::updatePlaygroundMusic(u32 row, u32 col, MusicInstruments *mi) {
    if (mi) {
        /// Vistor sets the image of the cell
        imageVisitor iv;
        mi->accept(iv);
        cells[row][col]->setImage(iv.getPixmap());
        Playground::getInstance()->enemyInsert(row, 50);
        qDebug() << "1";
        Playground::getInstance()->enemyMove();
        qDebug() << "2";
    } else {
        cells[row][col]->setImage(new QPixmap());
    }
}

void PlaygroundWidget::updatePlaygroundRobot(u32 row, u32 col, Robot *r) {
    qDebug() << "updatePlaygroundRobot";
    if (r) {
        /// Vistor sets the image of the cell
        imageVisitor iv;
        r->accept(iv);
        cells[row][col]->setImage(iv.getPixmap());
    } else {
        cells[row][col]->setImage(new QPixmap());
    }
}

void PlaygroundWidget::levelUpEntity() {
    if (getFocus()) {
    }
}

void PlaygroundWidget::setFocus(u32 row, u32 col) {
    hasFocus.row = row;
    hasFocus.col = col;
    // showUpdatePrice();
    qDebug() << "PlaygroundWidget::setFocus()";
}

void PlaygroundWidget::removeFocus() {
    hasFocus.row = -1;
    hasFocus.col = -1;
    qDebug() << "PlaygroundWidget::removeFocus()";
}

bool PlaygroundWidget::getFocus() const { return hasFocus.row != -1 && hasFocus.col != -1; }