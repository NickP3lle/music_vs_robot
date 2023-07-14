#include "player.h"

PlayerAbstract::PlayerAbstract(u32 health, u32 level) : h(health), l(level) {}

u32 PlayerAbstract::getLevel() const { return l; }

void PlayerAbstract::levelUp() { l++; }

std::string PlayerAbstract::toString() const {
  std::string s;
  s += "\"health\": " + std::to_string(h) + ",\n";
  s += "\"level\": " + std::to_string(l);
  return s;
}

Sample::Sample(u32 h, u32 l) : PlayerAbstract(h, l) {}

void Sample::accept(VisitorGUI *visitor) const { visitor->visitSample(); }

Sample *Sample::clone() const { return new Sample(*this); }

std::string Sample::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"Sample\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamageBullet *Sample::attack() const {
  return new DamageBullet(SAMPLE_POWER + getLevel() * SAMPLE_POWER_INCREASE);
}

void Sample::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += SAMPLE_HEALTH_INCREASE;
}

u32 Sample::getCost() const { return SAMPLE_PRICE * 0.75; }

u32 Sample::value() const { return getCost() + getLevel() * SAMPLE_PRICE; }

ThreeColumn::ThreeColumn(u32 h, u32 l) : PlayerAbstract(h, l) {}

void ThreeColumn::accept(VisitorGUI *visitor) const {
  visitor->visitThreeColumn();
}

ThreeColumn *ThreeColumn::clone() const { return new ThreeColumn(*this); }

std::string ThreeColumn::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"ThreeColumn\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamageWave *ThreeColumn::attack() const {
  return new DamageWave(THREE_COLUMN_POWER +
                        getLevel() * THREE_COLUMN_POWER_INCREASE);
}

void ThreeColumn::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += THREE_COLUMN_HEALTH_INCREASE;
}

u32 ThreeColumn::getCost() const { return THREE_COLUMN_PRICE * 0.75; }

u32 ThreeColumn::value() const {
  return getCost() + getLevel() * THREE_COLUMN_PRICE;
}

DoubleLife::DoubleLife(u32 h, u32 l, bool dl)
    : PlayerAbstract(h, l), secondLife(dl) {}

void DoubleLife::accept(VisitorGUI *visitor) const {
  visitor->visitDoubleLife();
}

DoubleLife *DoubleLife::clone() const { return new DoubleLife(*this); }

std::string DoubleLife::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"DoubleLife\",\n";
  s += PlayerAbstract::toString() + ",\n";
  s += "\"secondLife\": " + std::to_string(secondLife) + "\n";
  s += "}";
  return s;
}

DamageBullet *DoubleLife::attack() const {
  return new DamageBullet(DOUBLE_LIFE_POWER +
                          getLevel() * DOUBLE_LIFE_POWER_INCREASE);
}

bool DoubleLife::sufferDamage(Damage *damage) {
  if (!PlayerAbstract::sufferDamage(damage)) {
    return false;
  } else if (secondLife) {
    secondLife = false;
    getHealth() = DOUBLE_LIFE_HEALTH + getLevel() * DOUBLE_LIFE_HEALTH_INCREASE;
    return false;
  } else {
    return true;
  }
}

void DoubleLife::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += DOUBLE_LIFE_HEALTH_INCREASE;
}

u32 DoubleLife::getCost() const { return DOUBLE_LIFE_PRICE * 0.75; }

u32 DoubleLife::value() const {
  return getCost() + getLevel() * DOUBLE_LIFE_PRICE;
}

ThreeRow::ThreeRow(u32 h, u32 l) : PlayerAbstract(h, l) {}

void ThreeRow::accept(VisitorGUI *visitor) const { visitor->visitThreeRow(); }

ThreeRow *ThreeRow::clone() const { return new ThreeRow(*this); }

std::string ThreeRow::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"ThreeRow\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamageBullet *ThreeRow::attack() const {
  return new DamageBullet(THREE_ROW_POWER +
                          getLevel() * THREE_ROW_POWER_INCREASE);
}

void ThreeRow::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += THREE_ROW_HEALTH_INCREASE;
}

u32 ThreeRow::getCost() const { return THREE_ROW_PRICE * 0.75; }

u32 ThreeRow::value() const { return getCost() + getLevel() * THREE_ROW_PRICE; }

SlowDown::SlowDown(u32 h, u32 l) : PlayerAbstract(h, l) {}

void SlowDown::accept(VisitorGUI *visitor) const { visitor->visitSlowDown(); }

SlowDown *SlowDown::clone() const { return new SlowDown(*this); }

std::string SlowDown::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"SlowDown\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamageSlow *SlowDown::attack() const {
  return new DamageSlow(SLOW_DOWN_POWER + getLevel() * SLOW_DOWN_POWER_INCREASE,
                        1 + getLevel() / 2);
}

void SlowDown::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += SLOW_DOWN_HEALTH_INCREASE;
}

u32 SlowDown::getCost() const { return SLOW_DOWN_PRICE * 0.75; }

u32 SlowDown::value() const { return getCost() + getLevel() * SLOW_DOWN_PRICE; }
