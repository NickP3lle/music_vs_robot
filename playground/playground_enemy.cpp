#include "playground_enemy.h"
#include "playground_player.h"

void PlaygroundEnemy::insert(u32 r, u32 c, const EnemyWTool &e) {
  enemy[r][c].push_back(e);
  obs.iter([&](auto o) { o->update(r, c / FRAMES, &e); });
}

u32 PlaygroundEnemy::nearestPlayer(u32 r, u32 c, const PlaygroundPlayer &pp) {
  c--;

  if (!pp.isEmpty(r, c / FRAMES))
    return 0;

  for (u32 i = 1; i <= c / FRAMES; ++i) {
    if (!pp.isEmpty(r, c / FRAMES - i))
      return (i - 1) * FRAMES + c % FRAMES + 1;
  }

  return c + 1;
}

void PlaygroundEnemy::insert() {
  u32 r = randomInt(0, 1000) % ROWS;
  u32 d = Timer::getInstance()->get();
  insert(r, COLS * FRAMES - 1, EnemyWTool(d * 3 / 4, d));
}

bool PlaygroundEnemy::remove(u32 r, u32 c, const EnemyWTool &e) {
  bool f = false;
  c *= FRAMES;
  for (u32 i = c; i < c + FRAMES; ++i) {
    f = enemy[r][i].remove(e);
  }
  if (f) {
    notifyObservers(r, c / FRAMES);
  }
  return f;
}

bool PlaygroundEnemy::isEmpty(u32 r, u32 c) const {
  return get(r, c).size() == 0;
}

deque<EnemyWTool *> PlaygroundEnemy::get(u32 r, u32 c) {
  u32 size = 0;
  c *= FRAMES;
  for (u32 i = c; i < c + FRAMES; ++i) {
    size += enemy[r][i].size();
  }

  deque<EnemyWTool *> d(size);
  for (u32 i = c; i < c + FRAMES; ++i) {
    enemy[r][i].iter([&d](EnemyWTool &e) { d.push_back(&e); });
  }
  return d;
}

deque<const EnemyWTool *> PlaygroundEnemy::get(u32 r, u32 c) const {
  u32 size = 0;
  c *= FRAMES;
  for (u32 i = c; i < c + FRAMES; ++i) {
    size += enemy[r][i].size();
  }

  deque<const EnemyWTool *> d(size);
  for (u32 i = c; i < c + FRAMES; ++i) {
    enemy[r][i].iter([&d](EnemyWTool &e) { d.push_back(&e); });
  }
  return d;
}

deque<const EnemyWTool *> PlaygroundEnemy::getAttack(u32 r, u32 c) const {
  u32 size = 0;
  c *= FRAMES;
  for (u32 i = ++c; i < c + FRAMES; ++i) {
    size += enemy[r][i].size();
  }

  deque<const EnemyWTool *> d(size);
  for (u32 i = c; i < c + FRAMES; ++i) {
    enemy[r][i].iter([&d](EnemyWTool &e) { d.push_back(&e); });
  }
  return d;
}

void PlaygroundEnemy::attack(PlaygroundPlayer &p) const {
  for (u32 r = 0; r < ROWS; ++r) {
    for (u32 c = 0; c < COLS - 1; ++c) {
      if (!p.isEmpty(r, c)) {
        DamageEnemy d = DamageEnemy(0);
        getAttack(r, c).iter([&](const EnemyWTool *e) {
          DamageEnemy *tmp = e->attack();
          d = d + *tmp;
          delete tmp;
        });
        if (p.get(r, c).sufferDamage(d))
          p.remove(r, c);
      }
    }
  }
}

bool PlaygroundEnemy::move(const PlaygroundPlayer &pp, PlaygroundDamage &pd) {
  for (u32 r = 0; r < ROWS; ++r) {
    for (u32 c = 1; c < COLS * FRAMES; ++c) {

      // check if there is an player in the current cell
      if (!pp.isEmpty(r, c / FRAMES)) {
        c += FRAMES;
        continue;
      }

      u32 np = nearestPlayer(r, c, pp);
      while (enemy[r][c].size() > 0) {
        EnemyWTool e = enemy[r][c].pop_front();

        u32 mv = e.move() / (pd.isSlow(r, c / FRAMES) + 1);
        mv = c - std::min(mv, np);
        if (mv == 0) {
          insert(r, 0, e);
          return true;
        }

        enemy[r][mv].push_back(e); // don't need to notify observers
      }
    }
    for (u32 c = 0; c < COLS; ++c) {
      notifyObservers(r, c);
    }
  }
  return false;
}

void PlaygroundEnemy::notifyObservers(u32 r, u32 c) const {
  // if (isEmpty(r, c)) {
  //     obs.iter([&](auto o) { o->update(r, c, nullptr); });
  // } else {
  //     get(r, c).iter([&](auto e) { obs.iter([&](auto o) { o->update(r, c, e);
  //     }); });
  // }
  obs.iter([&](auto o) { o->update(r, c, nullptr); });
}
