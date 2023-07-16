#include "test_player.h"
#include <cassert>

bool Test_Sample_toString() {
  u32 l = randomInt(100, 50);
  u32 h = SAMPLE_HEALTH + SAMPLE_HEALTH_INCREASE * (l - 1);

  std::string expected = "{\n\"class\": \"Sample\",\n\"health\": ";
  expected += std::to_string(h);
  expected += ",\n\"level\": " + std::to_string(l) + "\n}";

  Sample sample(l);
  return sample.toString() == expected;
}

bool Test_Sample_attack() {
  u32 l = randomInt(100, 50);
  Sample sample(l);
  DamageBullet *damage = sample.attack();
  bool testPassed =
      (damage != nullptr) &&
      (damage->getDamage() == (SAMPLE_POWER + (l - 1) * SAMPLE_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_Sample_levelUp() {
  u32 l = randomInt(100, 50);
  u32 h = SAMPLE_HEALTH + l * SAMPLE_HEALTH_INCREASE;

  Sample sample(l++);
  sample.levelUp();

  bool testPassed = (sample.getLevel() == l && sample.getHealth() == h);

  return testPassed;
}

bool Test_Sample_getCost() {
  u32 l = randomInt(100, 50);
  Sample sample(l);
  return sample.getCost() ==
         (u32)(SAMPLE_PRICE * 0.75) + (l - 1) * SAMPLE_PRICE;
}

bool Test_ThreeColumn_toString() {
  u32 l = randomInt(100, 50);
  u32 h = THREE_COLUMN_HEALTH + THREE_COLUMN_HEALTH_INCREASE * (l - 1);

  std::string expected = "{\n\"class\": \"ThreeColumn\",\n\"health\": ";
  expected += std::to_string(h);
  expected += ",\n\"level\": " + std::to_string(l) + "\n}";

  ThreeColumn threeColumn(l);
  return threeColumn.toString() == expected;
}

bool Test_ThreeColumn_attack() {
  u32 l = randomInt(100, 50);
  u32 a = THREE_COLUMN_POWER + (l - 1) * THREE_COLUMN_POWER_INCREASE;

  ThreeColumn threeColumn(l);
  DamageWave *damage = threeColumn.attack();

  bool testPassed = (damage != nullptr) && (damage->getDamage() == a);
  delete damage;

  return testPassed;
}

bool Test_ThreeColumn_levelUp() {
  u32 l = randomInt(100, 50);
  u32 h = THREE_COLUMN_HEALTH + l * THREE_COLUMN_HEALTH_INCREASE;

  ThreeColumn threeColumn(l++);
  threeColumn.levelUp();

  bool testPassed =
      (threeColumn.getLevel() == l && threeColumn.getHealth() == h);

  return testPassed;
}

bool Test_ThreeColumn_getCost() {
  u32 l = randomInt(100, 50);
  ThreeColumn threeColumn(l);
  return threeColumn.getCost() ==
         (u32)(THREE_COLUMN_PRICE * 0.75) + (l - 1) * THREE_COLUMN_PRICE;
}

bool Test_DoubleLife_toString() {
  u32 l = randomInt(100, 50);
  u32 h = DOUBLE_LIFE_HEALTH + (l - 1) * DOUBLE_LIFE_HEALTH_INCREASE;

  std::string expected = "{\n\"class\": \"DoubleLife\",\n\"health\": ";
  expected += std::to_string(h);
  expected += ",\n\"level\": " + std::to_string(l) + ",";
  expected += "\n\"secondLife\": " + std::to_string(true) + "\n}";

  DoubleLife doubleLife(l);
  return doubleLife.toString() == expected;
}

bool Test_DoubleLife_attack() {
  u32 l = randomInt(100, 50);
  u32 a = DOUBLE_LIFE_POWER + (l - 1) * DOUBLE_LIFE_POWER_INCREASE;

  DoubleLife doubleLife(l);
  DamageBullet *damage = doubleLife.attack();

  bool testPassed = (damage != nullptr) && (damage->getDamage() == a);
  delete damage;

  return testPassed;
}

bool Test_DoubleLife_sufferDamage() {
  u32 l = randomInt(100, 50);

  DoubleLife doubleLife(l);
  u32 h = doubleLife.getHealth();
  DamageAbstract *damage = new DamageEnemy(h / 2);
  bool isBroken = doubleLife.sufferDamage(damage);
  bool testPassed = (!isBroken && doubleLife.getHealth() == h - h / 2);
  delete damage;

  damage = new DamageEnemy(h);
  isBroken = doubleLife.sufferDamage(damage);
  testPassed &= (!isBroken && doubleLife.getHealth() == h);
  delete damage;

  damage = new DamageEnemy(h);
  isBroken = doubleLife.sufferDamage(damage);
  testPassed &= (isBroken && doubleLife.getHealth() == 0);

  return testPassed;
}

bool Test_DoubleLife_levelUp() {
  u32 l = randomInt(100, 50);
  u32 h = DOUBLE_LIFE_HEALTH + l * DOUBLE_LIFE_HEALTH_INCREASE;

  DoubleLife doubleLife(l++);
  doubleLife.levelUp();

  bool testPassed = doubleLife.getLevel() == l && doubleLife.getHealth() == h;
  return testPassed;
}

bool Test_DoubleLife_getCost() {
  u32 l = randomInt(100, 50);

  DoubleLife doubleLife(l);
  return doubleLife.getCost() ==
         (u32)(DOUBLE_LIFE_PRICE * 0.75) + (l - 1) * DOUBLE_LIFE_PRICE;
}

bool Test_ThreeRow_toString() {
  u32 l = randomInt(100, 50);
  u32 h = THREE_ROW_HEALTH + (l - 1) * THREE_ROW_HEALTH_INCREASE;

  std::string expected = "{\n\"class\": \"ThreeRow\",\n\"health\": ";
  expected += std::to_string(h);
  expected += ",\n\"level\": " + std::to_string(l) + "\n}";

  ThreeRow threeRow(l);
  return threeRow.toString() == expected;
}

bool Test_ThreeRow_attack() {
  u32 l = randomInt(100, 50);
  u32 a = THREE_ROW_POWER + (l - 1) * THREE_ROW_POWER_INCREASE;

  ThreeRow threeRow(l);
  DamageBullet *damage = threeRow.attack();

  bool testPassed = (damage != nullptr) && (damage->getDamage() == a);
  delete damage;

  return testPassed;
}

bool Test_ThreeRow_levelUp() {
  u32 l = randomInt(100, 50);
  u32 h = THREE_ROW_HEALTH + l * THREE_ROW_HEALTH_INCREASE;

  ThreeRow threeRow(l++);
  threeRow.levelUp();
  bool testPassed = (threeRow.getLevel() == l && threeRow.getHealth() == h);

  return testPassed;
}

bool Test_ThreeRow_getCost() {
  u32 l = randomInt(100, 50);

  ThreeRow threeRow(l);
  return threeRow.getCost() ==
         (u32)(THREE_ROW_PRICE * 0.75) + (l - 1) * THREE_ROW_PRICE;
}

bool Test_SlowDown_toString() {
  u32 l = randomInt(100, 50);
  u32 h = SLOW_DOWN_HEALTH + (l - 1) * SLOW_DOWN_HEALTH_INCREASE;

  std::string expected = "{\n\"class\": \"SlowDown\",\n\"health\": ";
  expected += std::to_string(h);
  expected += ",\n\"level\": " + std::to_string(l) + "\n}";

  SlowDown slowDown(l);
  return slowDown.toString() == expected;
}

bool Test_SlowDown_attack() {
  u32 l = randomInt(100, 50);
  u32 a = (SLOW_DOWN_POWER + (l - 1) * SLOW_DOWN_POWER_INCREASE);

  SlowDown slowDown(l);
  DamageSlow *damage = slowDown.attack();
  bool testPassed = (damage != nullptr) && (damage->getDamage() == a);
  delete damage;

  return testPassed;
}

bool Test_SlowDown_levelUp() {
  u32 l = randomInt(100, 50);
  u32 h = SLOW_DOWN_HEALTH + l * SLOW_DOWN_HEALTH_INCREASE;

  SlowDown slowDown(l++);
  slowDown.levelUp();
  bool testPassed = (slowDown.getLevel() == l && slowDown.getHealth() == h);
  return testPassed;
}

bool Test_SlowDown_getCost() {
  u32 l = randomInt(100, 50);
  SlowDown slowDown(l);
  return slowDown.getCost() ==
         (SLOW_DOWN_PRICE * 0.75) + (l - 1) * SLOW_DOWN_PRICE;
}
