#include "playground.h"

Playground *Playground::instance = nullptr;

Playground *Playground::getInstance() {
  if (!instance) {
    instance = new Playground();
  }
  return instance;
}

Playground::~Playground() {
  if (instance) {
    delete instance;
    instance = nullptr;
  }
}

void Playground::cleanUp() { this->~Playground(); }

bool Playground::insert(u32 r, u32 c, PlayerAbstract *p) {
  return PlaygroundPlayer::insert(r, c, p);
}

bool Playground::remove(u32 r, u32 c) { return PlaygroundPlayer::remove(r, c); }

bool Playground::isEmpty(u32 r, u32 c) const {
  return PlaygroundPlayer::isEmpty(r, c);
}

PlayerAbstract *Playground::get(u32 r, u32 c) {
  return PlaygroundPlayer::get(r, c);
}

bool Playground::battle() {
  PlaygroundPlayer::attack(this);

  for (u32 i = 0; i < COLS; ++i) {
    PlaygroundDamage::move();
    PlaygroundDamage::attack(this);
    // there should be a timer of some kind here
  }

  PlaygroundEnemy::attack(this);
  if (PlaygroundEnemy::move(this)) {
    return true;
  }
  PlaygroundEnemy::insert();
  Timer::oneSecond();
  return false;
}
