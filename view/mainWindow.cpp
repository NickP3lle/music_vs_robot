#include "mainWindow.h"

#include "../playground/cash.h"
#include "../playground/game.h"
#include "../playground/timer.h"
#include "../util/data_manager.h"

#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), sw(new QStackedWidget(this)), counter(0) {

    setCentralWidget(sw); // set stackedWidget as central widget
    sw->addWidget(new StartWidget(this));
    sw->addWidget(new PlaygroundWidget(this));
    sw->setCurrentIndex(0);

    sw->resize(1280, 720);

    setWindowTitle("Music vs Robots");

    timer.setInterval(1000 / 11);
    connect(&timer, &QTimer::timeout, this, [this] {
        this->counter++;
        if (this->counter % 11 == 0) {
            Game::getInstance()->battle();
        } else {
            Game::getInstance()->damagePropagate();
        }
    });
}

void MainWindow::startGame() {
    sw->setCurrentIndex(1);
    // Errore qui
    Game::getInstance()->cleanUp();
    Timer::cleanUp();
    timer.start();
}

void MainWindow::newGame() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Select Difficulty");
    msgBox.setText("Select the level of difficulty:");

    QPushButton *easyButton = msgBox.addButton(tr("Easy"), QMessageBox::ActionRole);
    QPushButton *normalButton = msgBox.addButton(tr("Normal"), QMessageBox::ActionRole);
    QPushButton *hardButton = msgBox.addButton(tr("Hard"), QMessageBox::ActionRole);
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

    msgBox.exec();

    int difficulty = -1;
    Cash::cleanUp();

    if (msgBox.clickedButton() == easyButton) {
        Cash::add(2000);
        difficulty = 0;
    } else if (msgBox.clickedButton() == normalButton) {
        Cash::add(1000);
        difficulty = 1;
    } else if (msgBox.clickedButton() == hardButton) {
        Cash::add(500);
        difficulty = 2;
    } else if (msgBox.clickedButton() == abortButton) {
        return;
    }

    std::cout << "Difficulty: " << difficulty << std::endl;
    startGame();
}

void MainWindow::loadGame() {
    Cash::cleanUp();
    startGame();
    if (!DataManagerInterface::loadAll()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Failed to load game.");
        msgBox.exec();
        endGame();
    }
}

void MainWindow::endGame() {
    timer.stop();
    DataManagerInterface::saveAll();

    sw->setCurrentIndex(0);
}

MainWindow::~MainWindow() { DataManagerInterface::saveAll(); }
