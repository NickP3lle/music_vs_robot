#include "mainWindow.h"

#include "startWidget.h"
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Music vs Robots");
    StartWidget *startWidget = new StartWidget(this);
    setCentralWidget(startWidget);
    // startWidget->setStyleSheet("background-color:black;");
    startWidget->resize(1024, 576);
}