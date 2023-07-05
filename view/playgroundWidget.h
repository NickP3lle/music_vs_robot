#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include "../game/include.h"
#include "../game/playground.h"
#include "../game/timer.h"
#include "../music/music_instrument.h"
#include "observers/playgroundObserverInterface.h"
#include "playgroundComponents/cashWidget.h"
#include "playgroundComponents/instrumentButton.h"
#include "playgroundComponents/playgroundCellWidget.h"
#include "playgroundComponents/timerWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QWidget>

class PlaygroundWidget : public QWidget, public PlaygroundObserverInterface {
  Q_OBJECT

private:
  // Playground *playground;

  QPushButton *backButton;
  CashWidget *cash;
  TimerWidget *timer;

  InstrumentButton *violinButton;
  InstrumentButton *trumpetButton;
  InstrumentButton *drumButton;
  InstrumentButton *saxophoneButton;
  InstrumentButton *fluteButton;
  QPushButton *removeButton;

  PlaygroundCellWidget *cells[ROWS][COLUMNS];

private slots:
  /// Insert an entity in the playground
  void insertEntity(int row, int col);

public:
  PlaygroundWidget(QWidget *parent = 0);

  void clearPlayground() override;
  void updatePlaygroundMusic(u32 row, u32 col,
                             MusicInstruments *mi = nullptr) override;
  void updatePlaygroundRobot(u32 row, u32 col, Robot *r = nullptr) override;
};

#endif
