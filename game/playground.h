#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "../view/observers/playgroundObserverInterface.h"
#include "include.h"
#include "timer.h"
#include <chrono>
#include <thread>

class Playground : DataManagerInterface {
  private:
    ptr<MusicInstruments> player[ROWS][COLUMNS];
    deque<RobotWTool> enemy[ROWS][FRAME_COLUMNS * COLUMNS + 1];
    static Playground *instance;
    Playground();
    void reset();
    u32 nearestPlayer(u32 row, u32 col) const;
    template <typename S> void iterRobot(u32 row, u32 col, S fun);
    // std::string toString() const;
    // static bool fromString(const std::string &s);

    static std::vector<PlaygroundObserverInterface *> observers;
    static void notifyMusicObservers(int row, int col, MusicInstruments *mi = 0);
    static void notifyRobotObservers(int row, int col, Robot *r = 0);
    ~Playground();

  public:
    u32 damagePos;
    static void cleanUp();
    void enemyInsert(u32 row, u32 difficulty);
    bool isEmpty(u32 row, u32 col) const;
    const MusicInstruments *playerGet(u32 row, u32 col) const;
    void playerRemove(u32 row, u32 col);
    bool playerInsert(u32 row, u32 col, MusicInstruments *mi);
    bool playerLevelUp(u32 row, u32 col);
    bool lose() const;
    void playerAttack(u32 colonna);
    void damagePropagate(u32 colonna);
    void enemyAttack(u32 colonna);
    bool enemyMove();
    static void battle();
    //  std::ostream &print(std::ostream &) const;
    static Playground *getInstance();

    static void registerObserver(PlaygroundObserverInterface *obs);

    virtual std::string saveData() override;
    // bool loadData() override;
};

template <typename S> void Playground::iterRobot(u32 row, u32 col, S fun) {
    std::for_each(&enemy[row][col * FRAME_COLUMNS], &enemy[row][(col + 1) * FRAME_COLUMNS], fun);
}
#endif

/* come mi immagino il main, il realtà damagePropagate(i) dovrebbe essere
 * incluso in playerAttack(i)
void Playground::battle() {
}
*/
