#include "playground_enemy.h"
#include "playground_player.h"

PlaygroundEnemy *PlaygroundEnemy::instance = nullptr;

PlaygroundEnemy *PlaygroundEnemy::getInstance() {
  if (instance == nullptr) {
    instance = new PlaygroundEnemy();
  }
  return instance;
}

void PlaygroundEnemy::insert() {
  u32 r = randomInt(0, 1000) % ROWS;
  u32 d = Timer::getInstance()->get();
  this->enemy[r][COLS * FRAMES - 1].push_back(EnemyWTool(d * 3 / 4, d));
  notifyObservers(r, COLS - 1);
}

bool PlaygroundEnemy::remove(u32 r, u32 c, EnemyWTool &e) {
  bool f = false;
  c *= FRAMES;
  for (u32 i = c; i < c + FRAMES; ++i) {
    bool f = enemy[r][i].remove(e);
  }
  if (f)
    notifyObservers(r, c);
  return f;
}

bool PlaygroundEnemy::isEmpty(u32 r, u32 c) const {
  return get(r, c).size() > 0;
}

void PlaygroundEnemy::cleanUp() {
  if (instance != nullptr) {
    delete instance;
    instance = nullptr;
  }
}

deque<EnemyWTool *> PlaygroundEnemy::get(u32 r, u32 c) {
  deque<EnemyWTool *> d;
  for (u32 i = c * FRAMES; i < (c + 1) * FRAMES; ++i) {
    enemy[r][i].iter([&d](EnemyWTool &e) { d.push_back(&e); });
  }
  return d;
}

deque<const EnemyWTool *> PlaygroundEnemy::get(u32 r, u32 c) const {
  deque<const EnemyWTool *> d;
  for (u32 i = c * FRAMES; i < (c + 1) * FRAMES; ++i) {
    enemy[r][i].iter([&d](EnemyWTool &e) { d.push_back(&e); });
  }
  return d;
}

void PlaygroundEnemy::attack(PlaygroundPlayer *p) const {
  for (u32 r = 0; r < ROWS; ++r) {
    for (u32 c = 0; c < COLS; ++c) {
      if (!p->isEmpty(r, c)) {
        get(r, c)
            .iter([](EnemyWTool *e) { return e->attack(); })
            .iter([p, r, c](DamageEnemy &d) {
              if (p->get(r, c)->sufferDamage(&d))
                p->remove(r, c);
            });
      }
    }
  }
}
