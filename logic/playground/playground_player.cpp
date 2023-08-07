#include "playground_player.h"

bool PlaygroundPlayer::insert(u32 r, u32 c, PlayerAbstract *p) {
  if (this->player[r][c] || !Cash::getInstance()->sub(p->getCost())) {
    return false;
  }
  this->player[r][c] = p;
  notifyObservers(r, c);
  return true;
}

bool PlaygroundPlayer::remove(u32 r, u32 c) {
  if (!this->player[r][c]) {
    return false;
  }
  this->player[r][c] = nullptr;
  notifyObservers(r, c);
  return true;
}

bool PlaygroundPlayer::isEmpty(u32 r, u32 c) const {
  return !this->player[r][c];
}

bool PlaygroundPlayer::levelUp(u32 r, u32 c) const {
  if (!this->player[r][c] ||
      !Cash::getInstance()->sub(this->player[r][c]->getCost())) {
    return false;
  }
  this->player[r][c]->levelUp();
  // notify the level
  notifyObservers(r, c);
  return true;
}

PlayerAbstract *PlaygroundPlayer::get(u32 r, u32 c) {
  return &*this->player[r][c];
}

const PlayerAbstract *PlaygroundPlayer::get(u32 r, u32 c) const {
  return &*this->player[r][c];
}

void PlaygroundPlayer::attack(PlaygroundDamage *pd) const {
  for (u32 r = 0; r < ROWS; r++) {
    for (u32 c = 0; c < COLS - 1; c++) {
      if (this->player[r][c]) {
        pd->insert(r, c, this->player[r][c]->attack());
      }

      // ThreeRow attack the row above and below
      u32 u = 0;
      if (r > 0 && this->player[r - 1][c] &&
          dynamic_cast<const ThreeRow *>(&*this->player[r - 1][c])) {
        DamageAbstract *d = this->player[r - 1][c]->attack();
        u += d->getDamage();
        delete d;
      }
      if (r < ROWS - 1 && this->player[r + 1][c] &&
          dynamic_cast<const ThreeRow *>(&*this->player[r + 1][c])) {
        DamageAbstract *d = this->player[r + 1][c]->attack();
        u += d->getDamage();
        delete d;
      }

      if (!pd->isEmpty(r, c)) {
        pd->get(r, c)->getDamage() += u;
      } else if (u > 0) {
        pd->insert(r, c, new DamageBullet(u));
      }
    }
  }
}

void PlaygroundPlayer::notifyObservers(u32 r, u32 c) const {
  obs.iter([&](auto o) { o->update(r, c, this->get(r, c)); });
}
