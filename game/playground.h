#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "../view/observers/playgroundObserverInterface.h"
#include "include.h"

class Playground : DataManagerInterface {
private:
  ptr<MusicInstruments> player[ROWS][COLUMNS];
  deque<RobotWTool> enemy[ROWS][FRAME_COLUMNS * COLUMNS + 1];
  u32 damagePos;
  static Playground *instance;
  Playground();
  void reset();
  u32 nearestPlayer(u32 row, u32 col) const;
  u32 moveRobot(u32 row, u32 col, RobotWTool &robot);
  template <typename S> void iterRobot(u32 row, u32 col, S fun);
  std::string toString() const;
  static bool fromString(const std::string &s);

    static std::vector<PlaygroundObserverInterface *> observers;
    static void notifyMusicObservers(int row, int col, MusicInstruments *mi = 0);
    static void notifyRobotObservers(int row, int col, Robot *r = 0);

public:
  static void cleanUp();
  void enemyInsert(u32 row, u32 difficulty);
  bool playerInsert(u32 row, u32 col, MusicInstruments *mi);
  bool playerLevelUp(u32 row, u32 col);
  bool lose() const;
  void playerAttack(u32 colonna);
  void damagePropagate(u32 colonna);
  void enemyAttack(u32 colonna);
  void enemyMove();
  //  std::ostream &print(std::ostream &) const;
  static Playground *getInstance();

  static void registerObserver(PlaygroundObserverInterface *obs);

  bool saveData() override;
  bool loadData() override;
};

template <typename S> void Playground::iterRobot(u32 row, u32 col, S fun) {
  std::for_each(&enemy[row][col * FRAME_COLUMNS],
                &enemy[row][(col + 1) * FRAME_COLUMNS], fun);
}
#endif

/* come mi immagino il main, il realtà damagePropagate(i) dovrebbe essere
 * incluso in playerAttack(i)
void Playground::battle() {
  while (!lose()) {
    reset(); // reset damage
        incrementDifficulty();
    for (u32 i = 0; i < COLUMNS; i++) {
        attack(i);
         // ovvero (l'ordine è importante):
     // playerAttack(i);
     // damagePropagate(i);
     // enemyAttack(i);
      for (u32 j = 0; j < FRAME_COLUMNS; j++) {
        damagePos++;
        moveRobots();
        // here we might wanna add an observer
        // to notify the view to update
        //
        // view.update();
        //
        // checke if the player wanna do something
        //
        // if (view.playerAction()) {
                //   // controllo se vuole piazzare una pianta
                //   // oppure ne vuole togliere una
                //   // oppure la vuole aggiornare
                //   // oppure vuole uscire
        // }
      }
    }
  }
}
*/
