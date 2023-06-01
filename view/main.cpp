#include "mainWindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(1024, 576);
    window.show();

    return app.exec();
}