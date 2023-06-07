#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "playgroundWidget.h"
#include "startWidget.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

  private:
    StartWidget *startWidget;
    PlaygroundWidget *playgroundWidget;

    void showPlayground();

  public:
    MainWindow(QWidget *parent = 0);

  public slots:
    void startGame();
    void loadGame();
    void endGame();
};

#endif