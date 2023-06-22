#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "playgroundWidget.h"
#include "startWidget.h"
#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

  private:
    QStackedWidget *stackedWidget;
    StartWidget *startWidget;
    PlaygroundWidget *playgroundWidget;
    // bool hasUnsavedGame;

    void showPlayground();

  public:
    MainWindow(QWidget *parent = 0);

  public slots:
    void startGame();
    void loadGame();
    void endGame();

  signals:
    void startTimer();
};

#endif