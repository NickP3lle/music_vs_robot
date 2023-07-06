#include "mainWindow.h"

#include "../game/playground.h"
#include "../game/timer.h"

#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), stackedWidget(new QStackedWidget(this)), startWidget(new StartWidget(this)),
      playgroundWidget(new PlaygroundWidget(this)) {

    setCentralWidget(stackedWidget); // set stackedWidget as central widget
    stackedWidget->addWidget(startWidget);
    stackedWidget->addWidget(playgroundWidget);
    stackedWidget->setCurrentWidget(startWidget);

    stackedWidget->resize(1280, 720);

    setWindowTitle("Music vs Robots");
}

void MainWindow::showPlayground() {
    stackedWidget->setCurrentWidget(playgroundWidget);
    Timer::start();
    Playground::cleanUp();
    Cash::cleanUp();
    Cash::add(1000);
}

void MainWindow::startGame() { showPlayground(); }

void MainWindow::loadGame() {
    showPlayground();
    // load game
}

void MainWindow::endGame() {
    // QMessageBox::StandardButton reply;
    // reply =
    //     QMessageBox::question(this, "Music vs Robots", "Do you want to save the
    //     game?", QMessageBox::Yes | QMessageBox::No);
    // if (reply == QMessageBox::Yes) {
    // save game
    stackedWidget->setCurrentWidget(startWidget);
    Timer::stop();
    // }
}
