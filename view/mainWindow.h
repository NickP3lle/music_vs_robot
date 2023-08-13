#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../util/dataManager.h"
#include "playgroundWidget.h"
#include "startWidget.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  QStackedWidget *sw;
  QTimer timer;

  void startGame();

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:

  void newGame();
  void loadGame();
  void endGame();
};

#endif
