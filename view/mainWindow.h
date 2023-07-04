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

    /// Show the playground widget
    void showPlayground();

  public:
    MainWindow(QWidget *parent = 0);

  public slots:

    /// Change the current widget
    void startGame();
    void loadGame();
    void endGame();

  signals:
    /// Starts the timer when the game starts
    void startTimer();
};

#endif