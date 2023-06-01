#include "mainWindow.h"

#include "startWidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Music vs Robots");
    StartWidget *startWidget = new StartWidget(this);
    setCentralWidget(startWidget);
    startWidget->resize(1024, 576);
    startWidget->setStyleSheet("background-color:black;");
    setCentralWidget(startWidget);
    // centralWidget()->setLayout(new QVBoxLayout(this));
    // centralWidget()->layout()->addWidget(new QLabel("Main Window", this));
}