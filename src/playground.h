#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "../util/deque.h"
#include "entity.h"
#include "music/music_instrument.h"
#include "robot/robotwtool.h"
#include <array>
#include <climits>

#define COLUMNS 10
#define ROWS 5
#define FRAME_COLUMNS 6
typedef std::array<u32, ROWS> arr5;

class Playground {
private:
  ptr<MusicInstruments> player[ROWS][COLUMNS];
  deque<RobotWTool> enemy[ROWS][FRAME_COLUMNS * COLUMNS];
  u32 damage[ROWS]; // è utilizzato per tenere traccia dei danni in entrambe le
                    // direzioni player -> enemy e enemy -> player
  u32 damagePos;
  static Playground *instance;
  Playground();
  static void initPlayer();
  static void initEnemy();
  void reset();
  u32 cellEnemyAttack(u32 row, u32 colonna);
  u32 nearestPlayer(u32 row, u32 col) const;
  template <typename S> void iterRobot(u32 row, u32 col, S &&fun);
  void playerAttack(u32 colonna);
  void damagePropagate(u32 colonna);
  void enemyAttack(u32 colonna);

public:
  bool lose() const;
  void attack(u32 colonna);
  void moveRobots();
  static Playground *getInstance();
};

template <typename S> void Playground::iterRobot(u32 row, u32 col, S &&fun) {
  std::for_each(&enemy[row][col * FRAME_COLUMNS],
                &enemy[row][(col + 1) * FRAME_COLUMNS], fun);
}
#endif

/* come mi immagino il main, il realtà damagePropagate(i) dovrebbe essere
 * incluso in playerAttack(i)
void Playground::battle() {
  while (!lose()) {
    reset(); // reset damage
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
        // }
      }
    }
  }
}
*/
