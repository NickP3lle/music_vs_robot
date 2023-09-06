#include "playgroundWidget.h"

#include "visitors/imageVisitor.h"

#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include <QVBoxLayout>

PlaygroundWidget::PlaygroundWidget(QWidget *parent)
    : QWidget(parent), backButton(new QPushButton("Back", this)), cash(new CashWidget(this)), timer(new TimerWidget(this)),
      violinButton(new InstrumentButton(new SlowDown(), "Violin ", this)),
      trumpetButton(new InstrumentButton(new ThreeRow(), "Trumpet ", this)),
      drumButton(new InstrumentButton(new ThreeColumn(), "Drum ", this)),
      saxophoneButton(new InstrumentButton(new DoubleLife(), "Saxophone ", this)),
      fluteButton(new InstrumentButton(new Sample(), "Flute ", this)), levelUpButton(new QPushButton("Level Up", this)),
      removeButton(new QPushButton("Remove", this)), hasFocus({-1, -1}) {

    /// Observer
    Game::getInstance()->PlaygroundPlayer::addObserver(this);
    Game::getInstance()->PlaygroundEnemy::addObserver(this);
    Game::getInstance()->PlaygroundDamage::addObserver(this);
    Game::getInstance()->ObservableGameInterface::addObserver(this);

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
    connect(this, SIGNAL(callEndGame()), parent, SLOT(endGame()));

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

    connect(levelUpButton, SIGNAL(clicked()), this, SLOT(levelUpEntity()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeEntity()));

    /// Grid
    QGridLayout *gridLayout = new QGridLayout();

    gridLayout->setHorizontalSpacing(1);
    gridLayout->setVerticalSpacing(1);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            cells[row][col] = new PlaygroundCellWidget(this);
            if (col == COLS - 1) {
                cells[row][col]->setStyleSheet("background-color: #3d3d3d; border: 1px solid "
                                               "black;");
            }

            gridLayout->addWidget(cells[row][col], row, col);

            connect(cells[row][col], &PlaygroundCellWidget::clicked, this, [this, row, col] {
                setFocus(row, col);
                insertEntity();
                showUpdatePrice();
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

void PlaygroundWidget::insertEntity() {
    PlayerAbstract *m = InstrumentButton::getSelectedInstrument();

    if (!m) {
        qDebug() << "No instrument selected!";
        return;
    }

    if (hasFocus.col == COLS - 1) {
        qDebug() << "Cannot insert entity in the last column!";
        return;
    }

    if (Game::getInstance()->insert(hasFocus.row, hasFocus.col, *m)) {
        qDebug() << "Player inserted entity!";
    } else {
        qDebug() << "Player cannot insert entity!";
        return;
    }

    InstrumentButton::removeSelectedInstrument();
}

void PlaygroundWidget::update(u32 r, u32 c, const PlayerAbstract *p) {
    // std::cout << "PlaygroundWidget::update(PlayerAbstract)" << std::endl;
    if (p) {
        /// Vistor sets the image of the cell
        ImageVisitor iv;
        p->accept(&iv);
        cells[r][c]->setImage(iv.getPixmap());
        cells[r][c]->setLevel(p->getLevel());
    } else {
        std::cout << "PlaygroundWidget::update(PlayerAbstract) else" << std::endl;
        cells[r][c]->setImage(new QPixmap());
        cells[r][c]->hideLevel();
    }
}

void PlaygroundWidget::update(u32 r, u32 c, const EnemyWTool *e) {
    if (r == COLS)
        return;
    // qDebug() << "updatePlaygroundRobot";
    if (e) {
        /// Vistor sets the image of the cell
        ImageVisitor iv;
        e->accept(&iv);
        cells[r][c]->setImage(iv.getPixmap());
    } else {
        cells[r][c]->setImage(new QPixmap());
    }
}

void PlaygroundWidget::update(u32 r, u32 c, const DamageAbstract *d) {
    // if (d) {
    //     /// Vistor sets the image of the cell
    //     ImageVisitor iv;
    //     const DamagePlayer *dp = dynamic_cast<const DamagePlayer *>(d);
    //     if (dp == nullptr) {
    //         std::cout << "PlaygroundWidget::update(DamageAbstract) dp == nullptr" << std::endl;
    //         return;
    //     }
    //     dp->accept(&iv);
    //     cells[r][c]->setImage(iv.getPixmap());
    // } else {
    //     cells[r][c]->setImage(new QPixmap());
    // }
}

void PlaygroundWidget::clearGame() {
    for (u32 row = 0; row < ROWS; row++) {
        for (u32 col = 0; col < COLS; col++) {
            cells[row][col]->setImage(new QPixmap());
            cells[row][col]->hideLevel();
        }
    }
}

void PlaygroundWidget::gameOver() {
    QMessageBox msgBox;
    msgBox.setText("Game over!");
    int buttonClicked = msgBox.exec();

    if (buttonClicked == QMessageBox::Ok) {
        emit callEndGame();
        std::cout << "Game over!" << std::endl;
    }
}

void PlaygroundWidget::levelUpEntity() {
    Game *ptr = Game::getInstance();
    if (getFocus() && !ptr->isEmpty(hasFocus.row, hasFocus.col)) {
        if (ptr->levelUp(hasFocus.row, hasFocus.col)) {
            qDebug() << "Player level up entity!";
        }
        showUpdatePrice();
    } else {
        qDebug() << "Player cannot level up entity!";
    }
}

void PlaygroundWidget::removeEntity() {
    Game *ptr = Game::getInstance();
    if (getFocus() && !ptr->isEmpty(hasFocus.row, hasFocus.col)) {
        ptr->remove(hasFocus.row, hasFocus.col);
        qDebug() << "Player remove entity!";
    } else {
        qDebug() << "Player cannot remove entity!";
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

void PlaygroundWidget::showUpdatePrice() {
    // std::cout << "PlaygroundWidget::showUpdatePrice()" << std::endl;
    const PlayerAbstract *m = Game::getInstance()->get(hasFocus.row, hasFocus.col);
    if (m) {
        levelUpButton->setText("Level Up: " + QString::number(m->getCost()) + "$");
    } else {
        levelUpButton->setText("Level Up");
    }
}
