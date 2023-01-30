#include "music_instrument.h"

u32 MusicInstruments::damages[5][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

MusicInstruments::MusicInstruments(u32 life, u32 damage, u32 l)
    : Entity(life, damage), level(l){};

bool MusicInstruments::takeDamage(u32 &damage) {
  if (Entity::getHealth() > damage) {
    Entity::getHealth() -= damage;
    return false;
  }
  damage -= Entity::getHealth();
  return true;
}

u32 MusicInstruments::attack() const {
  return const_cast<MusicInstruments *>(this)->Entity::getPower();
}

ostream &MusicInstruments::print(ostream &os) const {
  MusicInstruments *it = const_cast<MusicInstruments *>(this);
  os << it->Entity::getHealth() << " " << it->Entity::getPower() << " " << level
     << "\n";
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

/// Flute

Flute::Flute(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l){};

Flute *Flute::clone() const { return new Flute(*this); }

void Flute::attack(u32 row) const {
  damages[row][0] += MusicInstruments::attack();
}

void Flute::levelUp() {
  MusicInstruments::levelUp();
  Entity::getHealth() += FLUTE_HEALTH_INCREASE;
  Entity::getPower() += FLUTE_POWER_INCREASE;
}

u32 Flute::value() const { return FLUTE_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Flute::print(ostream &os) const {
  os << "normie ";
  return MusicInstruments::print(os);
}

/// Drum

Drum::Drum(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l) {}

Drum *Drum::clone() const { return new Drum(*this); }

void Drum::attack(u32 row) const {}

void Drum::levelUp() {
  MusicInstruments::levelUp();
  Entity::getHealth() += DRUM_HEALTH_INCREASE;
  Entity::getPower() += DRUM_POWER_INCREASE;
}

u32 Drum::value() const { return DRUM_UPDATE_PRICE * (getLevel() + 0.75); }

ostream &Drum::print(ostream &os) const {
  os << "three_c ";
  return MusicInstruments::print(os);
}

/// Saxophone

Saxophone::Saxophone(u32 h, u32 p, u32 l, bool f)
    : MusicInstruments(h, p, l), secondLife(f){};

Saxophone *Saxophone::clone() const { return new Saxophone(*this); }

void Saxophone::attack(u32 row) const {}

void Saxophone::levelUp() {
  MusicInstruments::levelUp();
  secondLife = true;
  Entity::getHealth() += SAXOPHONE_HEALTH_INCREASE;
  Entity::getPower() += SAXOPHONE_POWER_INCREASE;
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

/// Trumpet

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
  Entity::getHealth() += TRUMPET_HEALTH_INCREASE;
  Entity::getPower() += TRUMPET_POWER_INCREASE;
}

u32 Trumpet::value() const {
  return TRUMPET_UPDATE_PRICE * (getLevel() + 0.75);
}

ostream &Trumpet::print(ostream &os) const {
  return os << "three_r ";
  return MusicInstruments::print(os);
}

/// Violin

Violin::Violin(u32 h, u32 p, u32 l) : MusicInstruments(h, p, l){};

Violin *Violin::clone() const { return new Violin(*this); }

void Violin::attack(u32 row) const {
  damages[row][0] += MusicInstruments::attack();
  damages[row][2] += slowDown();
}

void Violin::levelUp() {
  MusicInstruments::levelUp();
  Entity::getHealth() += VIOLIN_HEALTH_INCREASE;
  Entity::getPower() += VIOLIN_POWER_INCREASE;
}

u32 Violin::value() const { return VIOLIN_UPDATE_PRICE * (getLevel() + 0.75); }

u32 Violin::slowDown() const { return (1 + getLevel()) * 5; }

ostream &Violin::print(ostream &os) const {
  os << "slow ";
  return MusicInstruments::print(os);
}

music::music(music_enum type) : type(type) {}

music::music(u32 type) : type(static_cast<music_enum>(type)) {}

music::music(const MusicInstruments *const mi) {
  if (dynamic_cast<const Drum *const>(mi))
    type = music_enum::three_c;
  else if (dynamic_cast<const Flute *const>(mi))
    type = music_enum::normie;
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

music::music(const std::string &str) {
  if (str == "three_c")
    type = music_enum::three_c;
  else if (str == "normie")
    type = music_enum::normie;
  else if (str == "double_l")
    type = music_enum::double_l;
  else if (str == "three_r")
    type = music_enum::three_r;
  else if (str == "slow")
    type = music_enum::slow;
  else
    throw "music::music(const std::string &): not a music instrument";
}

bool music::operator==(const music &other) const { return type == other.type; }

// gets in input one line
// return a music instrument, which is saved just as you can print it
MusicInstruments *music::readMusic(std::istream &is) {
  std::string type;
  is >> type;
  u32 level, health, power;
  switch (music(type).type) {
  case (music_enum::three_c):
    is >> level >> health >> power;
    return new Drum(level, health, power);
  case (music_enum::normie):
    is >> level >> health >> power;
    return new Flute(level, health, power);
  case (music_enum::double_l):
    bool secondLife;
    is >> secondLife >> level >> health >> power;
    return new Saxophone(level, health, power, secondLife);
  case (music_enum::three_r):
    is >> level >> health >> power;
    return new Trumpet(level, health, power);
  case (music_enum::slow):
    is >> level >> health >> power;
    return new Violin(level, health, power);
  default:
    throw "music::readMusic(std::istream &): not a music instrument";
  }
}

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
