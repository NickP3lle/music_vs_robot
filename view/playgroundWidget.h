#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include "../game/include.h"
#include "../music/music_instrument.h"
#include "playgroundComponents/coinWidget.h"
#include "playgroundComponents/instrumentButton.h"
#include "playgroundComponents/playgroundCellWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QWidget>

class PlaygroundWidget : public QWidget {
    Q_OBJECT

  private:
    QPushButton *backButton;
    QLabel *timerLabel;
    CoinWidget *coins;
    QTimer *timer;

    InstrumentButton *violinButton;
    InstrumentButton *trumpetButton;
    InstrumentButton *drumButton;
    InstrumentButton *saxophoneButton;
    InstrumentButton *fluteButton;
    QPushButton *removeButton;

    PlaygroundCellWidget *cells[ROWS][COLUMNS];

  private slots:
    void startTimer();
    void updateTimerLabel(bool reset = false);

    /// Insert an entity in the playground
    void insertEntity(int row, int col);

  public:
    PlaygroundWidget(QWidget *parent = 0);
};

#endif