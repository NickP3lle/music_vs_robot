#include "music_instrument.h"

u32 MusicInstruments::damages[5][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

MusicInstruments::MusicInstruments(u32 life, u32 damage, u32 l)
    : Entity(life, damage), level(l) {}

bool MusicInstruments::takeDamage(u32 &amount) {
  if (getHealth() > amount) {
    getHealth() -= amount;
    return false;
  }
  amount -= getHealth();
  return true;
}
u32 MusicInstruments::attack() const {
  return (const_cast<MusicInstruments *>(this))->getPower();
}

ostream &MusicInstruments::print(ostream &os) const {
  MusicInstruments *it = const_cast<MusicInstruments *>(this);
  os << it->getHealth() << " " << it->getPower() << " " << level << "\n";
  return os;
}

void MusicInstruments::levelUp() { level += 1; }

u32 MusicInstruments::getLevel() const { return level; }

void MusicInstruments::resetDamages() {
  for (auto &row : damages) {
    for (auto &damage : row) {
      damage = 0;
    }
  }
}

/**
 * Flute
 */

Flute::Flute(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l){};

Flute *Flute::clone() const { return new Flute(*this); }

void Flute::attack(u32 row) const {
  damages[row][0] += MusicInstruments::attack();
}

void Flute::levelUp() {
  MusicInstruments::levelUp();
  getHealth() += FLUTE_HEALTH_INCREASE;
  getPower() += FLUTE_POWER_INCREASE;
}

u32 Flute::value() const { return FLUTE_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Flute::print(ostream &os) const {
  os << "normie ";
  return MusicInstruments::print(os);
}

void Flute::accept(EntityVisitorInterface &visitor) const {
  visitor.visitFlute();
}

/**
 * Drum
 */

Drum::Drum(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l) {}

Drum *Drum::clone() const { return new Drum(*this); }

void Drum::attack(u32 row) const {}

void Drum::levelUp() {
  MusicInstruments::levelUp();
  getHealth() += DRUM_HEALTH_INCREASE;
  getPower() += DRUM_POWER_INCREASE;
}

u32 Drum::value() const { return DRUM_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Drum::print(ostream &os) const {
  os << "three_c ";
  return MusicInstruments::print(os);
}

void Drum::accept(EntityVisitorInterface &visitor) const {
  visitor.visitDrum();
}

/**
 * Saxophone
 */

Saxophone::Saxophone(u32 h, u32 p, u32 l, bool f)
    : MusicInstruments(h, p, l), secondLife(f){};

Saxophone *Saxophone::clone() const { return new Saxophone(*this); }

void Saxophone::attack(u32 row) const {}

void Saxophone::levelUp() {
  MusicInstruments::levelUp();
  secondLife = true;
  getHealth() += SAXOPHONE_HEALTH_INCREASE;
  getPower() += SAXOPHONE_POWER_INCREASE;
}

u32 Saxophone::value() const {
  return SAXOPHONE_UPDATE_PRICE * (getLevel() + 0.75);
}

bool Saxophone::takeDamage(u32 &damage) {
  if (!MusicInstruments::takeDamage(damage))
    return false;
  if (secondLife) {
    secondLife = false;
    return false;
  }
  return true;
}

ostream &Saxophone::print(ostream &os) const {
  os << "double_l " << secondLife << " ";
  return MusicInstruments::print(os);
}

void Saxophone::accept(EntityVisitorInterface &visitor) const {
  visitor.visitSaxophone();
}

/**
 * Trumpet
 */

Trumpet::Trumpet(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l){};

Trumpet *Trumpet::clone() const { return new Trumpet(*this); }

void Trumpet::attack(u32 row) const {
  damages[row][0] += MusicInstruments::attack();
  if (row > 0)
    damages[row - 1][0] += MusicInstruments::attack();
  if (row < ROWS - 1)
    damages[row + 1][0] += MusicInstruments::attack();
}

void Trumpet::levelUp() {
  MusicInstruments::levelUp();
  getHealth() += TRUMPET_HEALTH_INCREASE;
  getPower() += TRUMPET_POWER_INCREASE;
}

u32 Trumpet::value() const {
  return TRUMPET_UPDATE_PRICE * (getLevel() + 0.75);
}

ostream &Trumpet::print(ostream &os) const {
  return os << "three_r ";
  return MusicInstruments::print(os);
}

void Trumpet::accept(EntityVisitorInterface &visitor) const {
  visitor.visitTrumpet();
}

/**
 * Violin
 */

Violin::Violin(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l){};

Violin *Violin::clone() const { return new Violin(*this); }

void Violin::attack(u32 row) const {
  damages[row][0] += MusicInstruments::attack();
  damages[row][2] += slowDown();
}

void Violin::levelUp() {
  MusicInstruments::levelUp();
  getHealth() += VIOLIN_HEALTH_INCREASE;
  getPower() += VIOLIN_POWER_INCREASE;
}

u32 Violin::value() const { return VIOLIN_UPDATE_PRICE * (getLevel() + 0.75); }

u32 Violin::slowDown() const { return (1 + getLevel()) * 5; }

ostream &Violin::print(ostream &os) const {
  os << "slow ";
  return MusicInstruments::print(os);
}

void Violin::accept(EntityVisitorInterface &visitor) const {
  visitor.visitViolin();
}
