#include "playground_damage.h"

void PlaygroundDamage::clear() {
  for (u32 r = 0; r < ROWS; r++) {
    for (u32 c = 0; c < COLS; c++) {
      damage[r][c] = nullptr;
      notifyObservers(r, c);
    }
  }
}

void PlaygroundDamage::insert(u32 r, u32 c, DamagePlayer *d) {
  this->damage[r][c] = d;
  notifyObservers(r, c);
}

bool PlaygroundDamage::remove(u32 r, u32 c) {
  if (isEmpty(r, c)) {
    return false;
  }
  this->damage[r][c] = nullptr;
  notifyObservers(r, c);
  return true;
}

bool PlaygroundDamage::isEmpty(u32 r, u32 c) const {
  return !this->damage[r][c];
}

DamagePlayer &PlaygroundDamage::get(u32 r, u32 c) {
  std::cout << "get damage!!" << std::endl;
  return *this->damage[r][c];
}

const DamagePlayer &PlaygroundDamage::get(u32 r, u32 c) const {
  return *this->damage[r][c];
}

void PlaygroundDamage::attack(PlaygroundEnemy *pe) {
  for (u32 r = 0; r < ROWS; r++) {
    for (u32 c = 0; c < COLS - 1; c++) {
      if (!isEmpty(r, c) && !pe->isEmpty(r, c)) {
        pe->get(r, c)
            .iter([&](EnemyWTool *e) { e->sufferDamage(get(r, c)); })
            .filter([](EnemyWTool *e) { return !e->isAlive(); })
            .iter([&](EnemyWTool **e) { pe->remove(r, c, *e); });

        notifyObservers(r, c);
      }
    }
  }
}

void PlaygroundDamage::move(PlaygroundEnemy *pe) {
  for (u32 r = 0; r < ROWS; r++) {

    // reset damage
    if (!isEmpty(r, COLS - 1))
      get(r, COLS - 1) / MAX_U32;

    for (int c = COLS - 2; c >= 0; c--) {
      if (!isEmpty(r, c)) {
        get(r, c).oneWave();

        // check if there is any enemy, if so slow doesn't move any more
        DamagePlayer d = get(r, c); // clone
        if (pe->isEmpty(r, c)) {
          damage[r][c] = nullptr;
        } else {
          d.resetSlow();
          get(r, c) / MAX_U32;
        }

        // check if there is already slow in the next cell
        if (!isEmpty(r, c + 1)) {
          d = get(r, c + 1) + d;
        }
        damage[r][c + 1] = &d;

        notifyObservers(r, c);
        notifyObservers(r, c + 1);
      }
    }
  }
}

bool PlaygroundDamage::isSlow(u32 r, u32 c) {
  return !isEmpty(r, c) && get(r, c).slow();
}

void PlaygroundDamage::notifyObservers(u32 r, u32 c) const {
  obs.iter([&](auto o) { o->update(r, c, &this->get(r, c)); });
}
