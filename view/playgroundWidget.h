#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include "../game/include.h"
#include "../game/playground.h"
#include "../music/music_instrument.h"
#include "observers/playgroundObserverInterface.h"
#include "playgroundComponents/cashWidget.h"
#include "playgroundComponents/instrumentButton.h"
#include "playgroundComponents/playgroundCellWidget.h"

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
    QLabel *timerLabel;
    CashWidget *cash;
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

    void updatePlayground(int row, int col, Entity *entity = nullptr) override;
    void updatePlaygroundMusic(int row, int col, MusicInstruments *mi = nullptr) override;
    void updatePlaygroundRobot(int row, int col, Robot *r = nullptr) override;
};

#endif