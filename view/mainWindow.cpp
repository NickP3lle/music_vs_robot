#include "mainWindow.h"

#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), startWidget(new StartWidget(this)), playgroundWidget(new PlaygroundWidget(this)) {

    setWindowTitle("Music vs Robots");
    setCentralWidget(startWidget);
    startWidget->resize(1024, 576);

    // setCentralWidget(playgroundWidget); // set playgroundWidget as central widget
    playgroundWidget->resize(1024, 576);
    playgroundWidget->hide();

    // connect(playgroundWidget, SIGNAL(endGame()), playgroundWidget, SLOT(hide()));
    // connect(playgroundWidget, SIGNAL(endGame()), startWidget, SLOT(show()));
    // connect(playgroundWidget, SIGNAL(endGame()), playgroundWidget, SLOT(reset()));
}

void MainWindow::showPlayground() {
    playgroundWidget->show();
    startWidget->hide();
    setCentralWidget(playgroundWidget);
}

void MainWindow::startGame() { showPlayground(); }

void MainWindow::loadGame() {
    showPlayground();
    // load game
}

void MainWindow::endGame() {
    startWidget->show();
    playgroundWidget->hide();
    setCentralWidget(startWidget);
    // if (startWidget->isWidgetType()) {
    //     startWidget->show();
    // } else {
    //     qDebug() << "Error: the widget is not a StartWidget";
    // }
}