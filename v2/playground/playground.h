#pragma once
#include "playground_damage.h"
#include "playground_enemy.h"
#include "playground_player.h"
#include "timer.h"

class Playground : public PlaygroundDamage,
                   public PlaygroundEnemy,
                   public PlaygroundPlayer {
private:
  static Playground *instance;

public:
  static Playground *getInstance();
  ~Playground();
  void cleanUp();
  bool insert(u32 r, u32 c, PlayerAbstract *p);
  bool remove(u32 r, u32 c);
  // bool levelUp(u32 r, u32 c); // don't need to overload, it's already defined
  // and it's not ambiguos
  bool isEmpty(u32 r, u32 c) const;
  PlayerAbstract *get(u32 r, u32 c);
  bool battle();
};
