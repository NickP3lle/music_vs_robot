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

    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, [] { Playground::getInstance()->battle(); });
}

void MainWindow::startGame() {
    stackedWidget->setCurrentWidget(playgroundWidget);
    Playground::cleanUp();
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
    timer.stop();
    // }
}
