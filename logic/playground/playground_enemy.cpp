#include "playground_enemy.h"
#include "playground_player.h"

void PlaygroundEnemy::insert(u32 r, u32 c, EnemyWTool &e) {
  enemy[r][c].push_back(e);
  obs.iter([&](auto o) { o->update(r, c, &e); });
}

u32 PlaygroundEnemy::nearestPlayer(u32 r, u32 c, PlaygroundPlayer *pp) {
  c--;

  if (pp->get(r, c / FRAMES))
    return 0;

  for (u32 i = 0; i <= c / FRAMES; ++i)
    if (!pp->isEmpty(r, c / FRAMES - i))
      return (i - 1) * FRAMES + c % FRAMES + 1;

  return c + 1;
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

bool PlaygroundEnemy::move(PlaygroundPlayer *pp) {
  for (u32 r = 0; r < ROWS; ++r) {
    for (u32 c = 1; c < COLS * FRAMES; ++c) {

      // check if there is an enemy in the current cell
      if (!pp->isEmpty(r, c / FRAMES)) {
        c += FRAMES;
        continue;
      }

      while (enemy[r][c].size() > 0) {
        EnemyWTool e = enemy[r][c].pop_front();
        u32 mv = e.move() / isSlow(r, c);
        mv = c - std::min(mv, nearestPlayer(r, c, pp));

        if (mv == 0) {
          obs.iter([](auto o) { o->notifyEndGame(); });
          return true;
        }
        insert(r, mv, e);
      }
    }
  }
  return false;
}

void PlaygroundEnemy::notifyObservers(u32 r, u32 c) const {
  obs.iter([&](auto o) { o->update(r, c, nullptr); });
  get(r, c).iter(
      [&](auto e) { obs.iter([&](auto o) { o->update(r, c, &e); }); });
}
