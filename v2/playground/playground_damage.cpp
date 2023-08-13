#include "playground_damage.h"

void PlaygroundDamage::insert(u32 r, u32 c, DamagePlayer *d) {
  this->damage[r][c] = d;
  notifyObservers(r, c);
}

bool PlaygroundDamage::remove(u32 r, u32 c) {
  if (!this->damage[r][c]) {
    return false;
  }
  this->damage[r][c] = nullptr;
  notifyObservers(r, c);
  return true;
}

bool PlaygroundDamage::isEmpty(u32 r, u32 c) const {
  return !this->damage[r][c];
}

DamagePlayer *PlaygroundDamage::get(u32 r, u32 c) {
  return &*this->damage[r][c];
}

const DamagePlayer *PlaygroundDamage::get(u32 r, u32 c) const {
  return &*this->damage[r][c];
}

void PlaygroundDamage::attack(PlaygroundEnemy *pe) {
  for (u32 r = 0; r < ROWS; r++) {
    for (u32 c = 0; c < COLS - 1; c++) {
      if (!isEmpty(r, c) && !pe->isEmpty(r, c)) {
        if (dynamic_cast<DamageWave *>(get(r, c))) {
          pe->get(r, c).iter([&](EnemyWTool *e) {
            e->sufferDamage(get(r, c));
            pe->remove(r, c, *e);
          });
        } else {
          if (pe->get(r, c)[0]->sufferDamage(get(r, c)))
            pe->remove(r, c, *pe->get(r, c)[0]);
          damage[r][c] = nullptr;
          notifyObservers(r, c);
        }
      }
    }
  }
}

void PlaygroundDamage::move() {
  for (u32 r = 0; r < ROWS; r++) {
    damage[r][COLS - 1] = nullptr;
    for (u32 c = COLS - 2; c >= 0; c--) {
      if (!isEmpty(r, c)) {
        DamageWave *dw = dynamic_cast<DamageWave *>(get(r, c));
        if (dw && dw->oneWave()) {
          damage[r][c] = nullptr;
          notifyObservers(r, c);
          continue;
        }
        damage[r][c + 1] = damage[r][c];
        damage[r][c] = nullptr;
        notifyObservers(r, c);
        notifyObservers(r, c + 1);
      }
    }
  }
}

bool PlaygroundDamage::isSlow(u32 r, u32 c) { return get(r, c)->slow(); }

void PlaygroundDamage::notifyObservers(u32 r, u32 c) const {
  obs.iter([&](auto o) { o->update(r, c, this->get(r, c)); });
}
