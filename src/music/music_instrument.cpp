#include "music_instrument.h"

MusicInstruments::MusicInstruments(u32 life, u32 damage)
    : health(life), power(damage), level(0){};

bool MusicInstruments::takeDamage(u32 &damage) {
  if (health > damage) {
    health -= damage;
    return false;
  }
  damage -= health;
  return true;
}

u32 MusicInstruments::attack() const { return power; }

void MusicInstruments::levelUp() { level += 1; }

u32 MusicInstruments::getLevel() const { return level; }

/// Flute

Flute::Flute() : MusicInstruments(FLUTE_DEFAULT_HEALTH, 100){};

Flute *Flute::clone() const { return new Flute(*this); }

void Flute::levelUp() {
  MusicInstruments::levelUp();
  health = FLUTE_DEFAULT_HEALTH + FLUTE_HEALTH_INCREASE * getLevel();
  power += FLUTE_POWER_INCREASE;
}

u32 Flute::value() const { return FLUTE_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Flute::print(ostream &os) const { return os << "F"; }

/// Drum

Drum::Drum() : MusicInstruments(DRUM_DEFAULT_HEALTH, 300) {}

Drum *Drum::clone() const { return new Drum(*this); }

void Drum::levelUp() {
  MusicInstruments::levelUp();
  health = DRUM_DEFAULT_HEALTH + DRUM_HEALTH_INCREASE * getLevel();
  power += DRUM_POWER_INCREASE;
}

u32 Drum::value() const { return DRUM_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Drum::print(ostream &os) const { return os << "D"; }

/// Saxophone

Saxophone::Saxophone() : MusicInstruments(SAXOPHONE_DEFAULT_HEALTH, 0){};

Saxophone *Saxophone::clone() const { return new Saxophone(*this); }

void Saxophone::levelUp() {
  MusicInstruments::levelUp();
  health =
      SAXOPHONE_DEFAULT_HEALTH + SAXOPHONE_HEALTH_INCREASE * (getLevel() - 1);
  power = SAXOPHONE_POWER_INCREASE;
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

ostream &Saxophone::print(ostream &os) const { return os << "S"; }

/// Trumpet

Trumpet::Trumpet() : MusicInstruments(TRUMPET_DEFAULT_HEALTH, 50){};

Trumpet *Trumpet::clone() const { return new Trumpet(*this); }

void Trumpet::levelUp() {
  MusicInstruments::levelUp();
  health = TRUMPET_DEFAULT_HEALTH + TRUMPET_HEALTH_INCREASE * (getLevel() - 1);
  power = TRUMPET_POWER_INCREASE;
}

u32 Trumpet::value() const {
  return TRUMPET_UPDATE_PRICE * (getLevel() + 0.75);
}

ostream &Trumpet::print(ostream &os) const { return os << "T"; }

/// Violin

Violin::Violin() : MusicInstruments(VIOLIN_DEFAULT_HEALTH, 100){};

Violin *Violin::clone() const { return new Violin(*this); }

void Violin::levelUp() {
  MusicInstruments::levelUp();
  health = VIOLIN_DEFAULT_HEALTH + VIOLIN_HEALTH_INCREASE * (getLevel() - 1);
  power = VIOLIN_POWER_INCREASE;
}

u32 Violin::value() const { return VIOLIN_UPDATE_PRICE * (getLevel() + 0.75); }

u32 Violin::slowDown() const { return (1 + getLevel()) * 5; }

ostream &Violin::print(ostream &os) const { return os << "V"; }

music::music(music_enum type) : type(type) {}

music::music(u32 type) : type(static_cast<music_enum>(type)) {}

music::operator unsigned int() const { return static_cast<u32>(*this); }

music::music(const MusicInstruments *const mi) {
  if (dynamic_cast<const Flute *const>(mi))
    type = music_enum::normie;
  else if (dynamic_cast<const Drum *const>(mi))
    type = music_enum::three_c;
  else if (dynamic_cast<const Saxophone *const>(mi))
    type = music_enum::double_l;
  else if (dynamic_cast<const Trumpet *const>(mi))
    type = music_enum::three_r;
  else if (dynamic_cast<const Violin *const>(mi))
    type = music_enum::slow;
  else
    throw "music::music(MusicInstruments *): not a music instrument";
}

music::music(const MusicInstruments &mi) : music(&mi) {}

MusicInstruments *music::New(music type) {
  switch (type.type) {
  case (NORMIE):
    return new Flute();
    break;
  case (THREE_C):
    return new Drum;
  case (DOUBLE_L):
    return new Saxophone();
  case (THREE_R):
    return new Trumpet();
  case (SLOW):
    return new Violin();
  default:
    throw "music::New(music): not a music type, check music_enum";
  }
}
