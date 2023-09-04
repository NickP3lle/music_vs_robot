#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include "../logic/entity/player.h"
#include "../logic/include.h"
#include "../logic/playground/playground.h"
#include "../logic/playground/timer.h"

#include "observers/playgroundObserverInterface.h"
#include "playgroundComponents/cashWidget.h"
#include "playgroundComponents/instrumentButton.h"
#include "playgroundComponents/playgroundCellWidget.h"
#include "playgroundComponents/timerWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

struct gridPosition {
    int row;
    int col;
};

class PlaygroundWidget : public QWidget, public PlaygroundObserverInterface {
    Q_OBJECT

  private:
    QPushButton *backButton;
    CashWidget *cash;
    TimerWidget *timer;

    InstrumentButton *violinButton;
    InstrumentButton *trumpetButton;
    InstrumentButton *drumButton;
    InstrumentButton *saxophoneButton;
    InstrumentButton *fluteButton;
    QPushButton *levelUpButton;
    QPushButton *removeButton;

    PlaygroundCellWidget *cells[ROWS][COLUMNS];

    gridPosition hasFocus;

    void showUpdatePrice();

  private slots:
    /// Insert an entity in the playground
    void insertEntity();
    void levelUpEntity();
    void removeEntity();

  public:
    PlaygroundWidget(QWidget *parent = 0);

    void setFocus(u32 row, u32 col);
    void removeFocus();
    bool getFocus() const;

    void clearPlayground() override;
    void updatePlaygroundMusic(u32 row, u32 col, const MusicInstruments *mi = nullptr) override;
    void updatePlaygroundRobot(u32 row, u32 col, const Robot *r = nullptr) override;
    void updateDamagePosition(u32 col) override;
    void notifyEndGame() override;

  signals:
    void callEndGame();
};

#endif
