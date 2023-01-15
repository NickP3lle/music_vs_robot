#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "include.h"

#define COLUMNS 10
#define ROWS 5
#define FRAME_COLUMNS 6

class Playground {
public:
  ptr<MusicInstruments> player[ROWS][COLUMNS];
  deque<RobotWTool> enemy[ROWS][FRAME_COLUMNS * COLUMNS];
  u32 damage[ROWS][2]; // è utilizzato per tenere traccia dei danni in entrambe
                       // le 0: bullets, 1: drums
  // direzioni player -> enemy e enemy -> player
  u32 slowDown[ROWS];
  u32 damagePos;
  static Playground *instance;
  Playground();
  void reset();
  u32 nearestPlayer(u32 row, u32 col) const;
  u32 moveRobot(u32 row, u32 col, RobotWTool &robot);
  template <typename S> void iterRobot(u32 row, u32 col, S fun);

public:
  static void cleanUp();
  void insertEnemy(u32 row, u32 difficulty);
  bool insertPlayer(u32 row, u32 col, music mi_id);
  bool playerLevelUp(u32 row, u32 col);
  bool lose() const;
  void playerAttack(u32 colonna);
  void damagePropagate(u32 colonna);
  void enemyAttack(u32 colonna);
  void moveRobots();
  std::ostream &print(std::ostream &) const;
  static Playground *getInstance();
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
