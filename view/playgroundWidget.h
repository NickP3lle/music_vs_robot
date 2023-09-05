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

  private slots:
    void insertEntity();
    void levelUpEntity();
    void removeEntity();

  public:
    PlaygroundWidget(QWidget *parent = 0);

    void setFocus(u32 row, u32 col);
    void removeFocus();
    bool getFocus() const;

    // void clearPlayground() override;
    // void updatePlaygroundMusic(u32 row, u32 col, const MusicInstruments *mi = nullptr) override;
    // void updatePlaygroundRobot(u32 row, u32 col, const Robot *r = nullptr) override;
    // void updateDamagePosition(u32 col) override;
    // void notifyEndGame() override;

    void update(u32 r, u32 c, const PlayerAbstract *p) override {
        std::cout << "Player: " << r << " " << c << " " << (p ? p->toString() : "emptied") << std::endl;
    }

    void update(u32 r, u32 c, const EnemyWTool *e) override {
        if (e) {
        }
        std::cout << "Enemy: " << r << " " << c << " robot" << std::endl;
    }

    void update(u32 r, u32 c, const DamageAbstract *d) override {
        ptr<DamagePlayer> dmg = static_cast<const DamagePlayer *>(d);
        if (d) {
            std::cout << "Damage: " << r << " " << c << " " << dmg->getSlow() << " " << dmg->damage() << std::endl;
        }
    }

    void clearGame() override { std::cout << "Prova: clearGame" << std::endl; }

    void gameOver() override {
        std::cout << "Prova: loseGame" << std::endl;
        // l = true;
    }

  signals:
    void callEndGame();
};

#endif
