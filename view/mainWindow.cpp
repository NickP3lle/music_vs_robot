#include "mainWindow.h"

#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), stackedWidget(new QStackedWidget(this)), startWidget(new StartWidget(this)),
      playgroundWidget(new PlaygroundWidget(this)) {

    setCentralWidget(stackedWidget); // set stackedWidget as central widget
    stackedWidget->addWidget(startWidget);
    stackedWidget->addWidget(playgroundWidget);
    stackedWidget->setCurrentWidget(startWidget);

    stackedWidget->resize(1024, 576);

    setWindowTitle("Music vs Robots");
}

void MainWindow::showPlayground() { stackedWidget->setCurrentWidget(playgroundWidget); }

void MainWindow::startGame() {
    showPlayground();
    emit startTimer();
}

void MainWindow::loadGame() {
    showPlayground();
    // load game
}

void MainWindow::endGame() { stackedWidget->setCurrentWidget(startWidget); }