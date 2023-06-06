#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = 0);

  public slots:
    void startGame();

  signals:
    void showPlayground();
    // void endGame();
};

#endif