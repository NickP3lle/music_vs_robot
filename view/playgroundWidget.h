#ifndef PLAYGROUND_WIDGET_H
#define PLAYGROUND_WIDGET_H

#include "../entity/player.h"
#include "../include.h"
#include "../playground/game.h"
#include "../playground/timer.h"
#include "playgroundComponents/cashWidget.h"
#include "playgroundComponents/instrumentButton.h"
#include "playgroundComponents/playgroundCellWidget.h"
#include "playgroundComponents/timerWidget.h"
#include "visitors/imageVisitor.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

struct gridPosition {
    int row;
    int col;
};

class PlaygroundWidget : public QWidget,
                         public ObserverPlaygroundInterface<PlayerAbstract>,
                         public ObserverPlaygroundInterface<EnemyWTool>,
                         public ObserverPlaygroundInterface<DamageAbstract>,
                         public ObserverGameInterface {
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

    PlaygroundCellWidget *cells[ROWS][COLS];

    gridPosition hasFocus;

    void showUpdatePrice();
    void updateCell(u32 row, u32 col);

  private slots:
    void insertEntity();
    void levelUpEntity();
    void removeEntity();

  public:
    PlaygroundWidget(QWidget *parent = 0);

    void setFocus(u32 row, u32 col);
    void removeFocus();
    bool getFocus() const;

    // void updateDamagePosition(u32 col) override;

    void update(u32 r, u32 c, const PlayerAbstract *p) override;
    void update(u32 r, u32 c, const EnemyWTool *e) override;
    void update(u32 r, u32 c, const DamageAbstract *d) override;
    void clearGame() override;
    void gameOver() override;

  signals:
    void callEndGame();
};

#endif
