#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "playgroundWidget.h"
#include "startWidget.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  QStackedWidget *stackedWidget;
  StartWidget *startWidget;
  PlaygroundWidget *playgroundWidget;
  QTimer timer;

  // bool hasUnsavedGame;

public:
  MainWindow(QWidget *parent = 0);

public slots:

  /// Change the current widget
  void startGame();
  void loadGame();
  void endGame();
};

#endif
