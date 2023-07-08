#include "view/mainWindow.h"
#include <QApplication>
#include <QWidget>
#include <iostream>

int main(int argc, char *argv[]) {
  //    QApplication app(argc, argv);
  //
  //    MainWindow window;
  //    window.resize(1280, 720);
  //    window.show();
  //
  //    return app.exec();
  while (true) {
    Playground::battle();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}
