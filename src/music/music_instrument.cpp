#include "music_instrument.h"

MusicInstruments::MusicInstruments(u32 life, u32 damage)
    : Entity(life, damage), level(1){};

bool MusicInstruments::checkLevelUp(u32 price) {
  if (level >= 3) {
    // std::cerr << "Level max already reached\n";
    return false;
  }
  if (!(Cash::getInstance()->sub(price))) {
    // std::cerr << "You don't have enough money" << std::endl;
    return false;
  }

  level += 1;

  // std::cerr << "Successfully leveled up\n";
  // std::cerr << "Level: " << level << std::endl;

  return true;
}

u32 MusicInstruments::attack() const { return getPower(); }

u32 MusicInstruments::getLevel() const { return level; }

Flute::Flute() : MusicInstruments(FLUTE_DEFAULT_HEALTH, 100){};

Flute *Flute::clone() const { return new Flute(*this); }

bool Flute::levelUp() {
  if (!(checkLevelUp(FLUTE_UPDATE_PRICE))) {
    return false;
  }

  // level è già stato incrementato
  updateHealth(FLUTE_DEFAULT_HEALTH +
               (FLUTE_HEALTH_INCREASE * (getLevel() - 1)));
  updatePower(FLUTE_POWER_INCREASE);
  return true;
}

Drum::Drum() : MusicInstruments(DRUM_DEFAULT_HEALTH, 300) {}

Drum *Drum::clone() const { return new Drum(*this); }

bool Drum::levelUp() {
  if (!(checkLevelUp(DRUM_UPDATE_PRICE))) {
    return false;
  }

  // level è già stato incrementato
  updateHealth(DRUM_DEFAULT_HEALTH + (DRUM_HEALTH_INCREASE * (getLevel() - 1)));
  updatePower(DRUM_POWER_INCREASE);
  return true;
}

Saxophone::Saxophone() : MusicInstruments(SAXOPHONE_DEFAULT_HEALTH, 0){};

bool Saxophone::takeDamage(u32 &damage) {
  if (!Entity::takeDamage(damage))
    return false;
  if (secondLife) {
    secondLife = false;
    return false;
  }
  return true;
}

Saxophone *Saxophone::clone() const { return new Saxophone(*this); }

bool Saxophone::levelUp() {
  if (!(checkLevelUp(SAXOPHONE_UPDATE_PRICE))) {
    return false;
  }

  // level è già stato incrementato
  updateHealth(SAXOPHONE_DEFAULT_HEALTH +
               (SAXOPHONE_HEALTH_INCREASE * (getLevel() - 1)));
  updatePower(SAXOPHONE_POWER_INCREASE);
  return true;
}

Trumpet::Trumpet() : MusicInstruments(TRUMPET_DEFAULT_HEALTH, 50){};

Trumpet *Trumpet::clone() const { return new Trumpet(*this); }

bool Trumpet::levelUp() {
  if (!(checkLevelUp(TRUMPET_UPDATE_PRICE))) {
    return false;
  }

  // level è già stato incrementato
  updateHealth(TRUMPET_DEFAULT_HEALTH +
               (TRUMPET_HEALTH_INCREASE * (getLevel() - 1)));
  updatePower(TRUMPET_POWER_INCREASE);
  return true;
}

Violin::Violin() : MusicInstruments(VIOLIN_DEFAULT_HEALTH, 100){};

Violin *Violin::clone() const { return new Violin(*this); }

bool Violin::levelUp() {
  if (!(checkLevelUp(VIOLIN_UPDATE_PRICE))) {
    return false;
  }

  // level è già stato incrementato
  updateHealth(VIOLIN_DEFAULT_HEALTH +
               (VIOLIN_HEALTH_INCREASE * (getLevel() - 1)));
  updatePower(VIOLIN_POWER_INCREASE);
  return true;
}

MusicInstruments *music::New(u32 type) {
  if (type == 0)
    return new Flute();
  else if (type == 1)
    return new Drum();
  else if (type == 2)
    return new Saxophone();
  else if (type == 3)
    return new Trumpet();
  else
    return new Violin();
}
