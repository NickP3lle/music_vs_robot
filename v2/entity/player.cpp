#include "player.h"

PlayerAbstract::PlayerAbstract(u32 health, u32 level) : h(health), l(level) {}

u32 &PlayerAbstract::getHealth() { return h; }

u32 PlayerAbstract::getLevel() const { return l; }

void PlayerAbstract::levelUp() { l++; }

std::string PlayerAbstract::toString() const {
  std::string s;
  s += "\"health\": " + std::to_string(h) + ",\n";
  s += "\"level\": " + std::to_string(l);
  return s;
}

Sample::Sample(u32 l)
    : PlayerAbstract(SAMPLE_HEALTH + SAMPLE_HEALTH_INCREASE * (l - 1), l) {}

void Sample::accept(VisitorInterface *visitor) const { visitor->visitSample(); }

Sample *Sample::clone() const { return new Sample(*this); }

std::string Sample::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"Sample\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamagePlayer *Sample::attack() const {
  return new DamagePlayer(
      SAMPLE_POWER + (getLevel() - 1) * SAMPLE_POWER_INCREASE, 0, 0);
}

void Sample::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += SAMPLE_HEALTH_INCREASE;
}

u32 Sample::getCost() const {
  return SAMPLE_PRICE * 0.75 + (getLevel() - 1) * SAMPLE_PRICE;
}

ThreeColumn::ThreeColumn(u32 l)
    : PlayerAbstract(
          THREE_COLUMN_HEALTH + THREE_COLUMN_HEALTH_INCREASE * (l - 1), l) {}

void ThreeColumn::accept(VisitorInterface *visitor) const {
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

DamagePlayer *ThreeColumn::attack() const {
  return new DamagePlayer(0, 0,
                          THREE_COLUMN_POWER +
                              (getLevel() - 1) * THREE_COLUMN_POWER_INCREASE);
}

void ThreeColumn::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += THREE_COLUMN_HEALTH_INCREASE;
}

u32 ThreeColumn::getCost() const {
  return THREE_COLUMN_PRICE * 0.75 + (getLevel() - 1) * THREE_COLUMN_PRICE;
}

DoubleLife::DoubleLife(u32 l, bool dl)
    : PlayerAbstract(DOUBLE_LIFE_HEALTH + DOUBLE_LIFE_HEALTH_INCREASE * (l - 1),
                     l),
      secondLife(dl) {}

void DoubleLife::accept(VisitorInterface *visitor) const {
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

DamagePlayer *DoubleLife::attack() const {
  return new DamagePlayer(
      0, 0, DOUBLE_LIFE_POWER + (getLevel() - 1) * DOUBLE_LIFE_POWER_INCREASE);
}

bool DoubleLife::sufferDamage(DamageAbstract *damage) {
  if (!EntityAbstract::sufferDamage(damage)) {
    return false;
  } else if (secondLife) {
    secondLife = false;
    getHealth() =
        DOUBLE_LIFE_HEALTH + (getLevel() - 1) * DOUBLE_LIFE_HEALTH_INCREASE;
    return false;
  } else {
    return true;
  }
}

void DoubleLife::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += DOUBLE_LIFE_HEALTH_INCREASE;
}

u32 DoubleLife::getCost() const {
  return DOUBLE_LIFE_PRICE * 0.75 + (getLevel() - 1) * DOUBLE_LIFE_PRICE;
}

ThreeRow::ThreeRow(u32 l)
    : PlayerAbstract(THREE_ROW_HEALTH + THREE_ROW_POWER_INCREASE * (l - 1), l) {
}

void ThreeRow::accept(VisitorInterface *visitor) const {
  visitor->visitThreeRow();
}

ThreeRow *ThreeRow::clone() const { return new ThreeRow(*this); }

std::string ThreeRow::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"ThreeRow\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamagePlayer *ThreeRow::attack() const {
  return new DamagePlayer(
      THREE_ROW_POWER + (getLevel() - 1) * THREE_ROW_POWER_INCREASE, 0, 0);
}

void ThreeRow::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += THREE_ROW_HEALTH_INCREASE;
}

u32 ThreeRow::getCost() const {
  return THREE_ROW_PRICE * 0.75 + (getLevel() - 1) * THREE_ROW_PRICE;
}

SlowDown::SlowDown(u32 l)
    : PlayerAbstract(SLOW_DOWN_HEALTH + SLOW_DOWN_HEALTH_INCREASE * (l - 1),
                     l) {}

void SlowDown::accept(VisitorInterface *visitor) const {
  visitor->visitSlowDown();
}

SlowDown *SlowDown::clone() const { return new SlowDown(*this); }

std::string SlowDown::toString() const {
  std::string s;
  s += "{\n";
  s += "\"class\": \"SlowDown\",\n";
  s += PlayerAbstract::toString() + "\n";
  s += "}";
  return s;
}

DamagePlayer *SlowDown::attack() const {
  return new DamagePlayer(SLOW_DOWN_POWER +
                              (getLevel() - 1) * SLOW_DOWN_POWER_INCREASE,
                          1 + getLevel() / 2, 0);
}

void SlowDown::levelUp() {
  PlayerAbstract::levelUp();
  getHealth() += SLOW_DOWN_HEALTH_INCREASE;
}

u32 SlowDown::getCost() const {
  return SLOW_DOWN_PRICE * 0.75 + (getLevel() - 1) * SLOW_DOWN_PRICE;
}
