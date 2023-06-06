#include "mainWindow.h"

#include "playgroundWidget.h"
#include "startWidget.h"
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Music vs Robots");
    StartWidget *startWidget = new StartWidget(this);
    setCentralWidget(startWidget);
    // startWidget->setStyleSheet("background-color:black;"); // set background color for debug
    startWidget->resize(1024, 576);

    PlaygroundWidget *playgroundWidget = new PlaygroundWidget(this);
    // setCentralWidget(playgroundWidget); // set playgroundWidget as central widget
    playgroundWidget->resize(1024, 576);
    playgroundWidget->hide();

    connect(this, SIGNAL(showPlayground()), playgroundWidget, SLOT(show()));
    connect(this, SIGNAL(showPlayground()), startWidget, SLOT(hide()));

    // connect(playgroundWidget, SIGNAL(endGame()), playgroundWidget, SLOT(hide()));
    // connect(playgroundWidget, SIGNAL(endGame()), startWidget, SLOT(show()));
    // connect(playgroundWidget, SIGNAL(endGame()), playgroundWidget, SLOT(reset()));
}

void MainWindow::startGame() { emit showPlayground(); }