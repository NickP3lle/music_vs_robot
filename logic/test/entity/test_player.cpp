#include "test_player.h"
#include <cassert>

bool Test_Sample_toString() {
  Sample sample(5);
  std::string expected = "{\n\"class\": \"Sample\",\n\"health\": " +
                         std::to_string(SAMPLE_HEALTH) + ",\n\"level\": 5}";
  return sample.toString() == expected;
}

bool Test_Sample_attack() {
  Sample sample(5);
  DamageBullet *damage = sample.attack();
  bool testPassed =
      (damage != nullptr) &&
      (damage->getDamage() ==
       (SAMPLE_POWER + sample.getLevel() * SAMPLE_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_Sample_levelUp() {
  Sample sample(5);
  sample.levelUp();
  bool testPassed =
      (sample.getLevel() == 6 &&
       sample.getHealth() == SAMPLE_HEALTH + SAMPLE_HEALTH_INCREASE);
  return testPassed;
}

bool Test_Sample_getCost() {
  Sample sample(5);
  return sample.getCost() == (SAMPLE_PRICE * 0.75);
}

bool Test_Sample_value() {
  Sample sample(5);
  return sample.value() ==
         (sample.getCost() + sample.getLevel() * SAMPLE_PRICE);
}

bool Test_ThreeColumn_toString() {
  ThreeColumn threeColumn(7);
  std::string expected = "{\n\"class\": \"ThreeColumn\",\n\"health\": " +
                         std::to_string(THREE_COLUMN_HEALTH) +
                         ",\n\"level\": 7}";
  return threeColumn.toString() == expected;
}

bool Test_ThreeColumn_attack() {
  ThreeColumn threeColumn(7);
  DamageWave *damage = threeColumn.attack();
  bool testPassed = (damage != nullptr) &&
                    (damage->getDamage() ==
                     (THREE_COLUMN_POWER +
                      threeColumn.getLevel() * THREE_COLUMN_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_ThreeColumn_levelUp() {
  ThreeColumn threeColumn(7);
  threeColumn.levelUp();
  bool testPassed = (threeColumn.getLevel() == 8 &&
                     threeColumn.getHealth() ==
                         THREE_COLUMN_HEALTH + THREE_COLUMN_HEALTH_INCREASE);
  return testPassed;
}

bool Test_ThreeColumn_getCost() {
  ThreeColumn threeColumn(7);
  return threeColumn.getCost() == (THREE_COLUMN_PRICE * 0.75);
}

bool Test_ThreeColumn_value() {
  ThreeColumn threeColumn(7);
  return threeColumn.value() ==
         (threeColumn.getCost() + threeColumn.getLevel() * THREE_COLUMN_PRICE);
}

bool Test_DoubleLife_toString() {
  DoubleLife doubleLife(9, true);
  std::string expected = "{\n\"class\": \"DoubleLife\",\n\"health\": " +
                         std::to_string(DOUBLE_LIFE_HEALTH) +
                         ",\n\"level\": 9,\n\"secondLife\": 1}";
  return doubleLife.toString() == expected;
}

bool Test_DoubleLife_attack() {
  DoubleLife doubleLife(9, true);
  DamageBullet *damage = doubleLife.attack();
  bool testPassed = (damage != nullptr) &&
                    (damage->getDamage() ==
                     (DOUBLE_LIFE_POWER +
                      doubleLife.getLevel() * DOUBLE_LIFE_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_DoubleLife_sufferDamage() {
  DoubleLife doubleLife(9, true);
  DamageAbstract *damage = new DamageBullet(150);
  bool isBroken = doubleLife.sufferDamage(damage);
  bool testPassed = (!isBroken && doubleLife.getHealth() == 50 &&
                     doubleLife.getLevel() == 9 &&
                     doubleLife.getHealth() ==
                         DOUBLE_LIFE_HEALTH + doubleLife.getLevel() *
                                                  DOUBLE_LIFE_HEALTH_INCREASE);
  delete damage;

  damage = new DamageBullet(60);
  isBroken = doubleLife.sufferDamage(damage);
  testPassed &= (isBroken && doubleLife.getHealth() == 0 &&
                 doubleLife.getLevel() == 9 && doubleLife.getHealth() == 0);
  delete damage;

  return testPassed;
}

bool Test_DoubleLife_levelUp() {
  DoubleLife doubleLife(9, true);
  doubleLife.levelUp();
  bool testPassed = (doubleLife.getLevel() == 10 &&
                     doubleLife.getHealth() ==
                         DOUBLE_LIFE_HEALTH + DOUBLE_LIFE_HEALTH_INCREASE);
  return testPassed;
}

bool Test_DoubleLife_getCost() {
  DoubleLife doubleLife(9, true);
  return doubleLife.getCost() == (DOUBLE_LIFE_PRICE * 0.75);
}

bool Test_DoubleLife_value() {
  DoubleLife doubleLife(9, true);
  return doubleLife.value() ==
         (doubleLife.getCost() + doubleLife.getLevel() * DOUBLE_LIFE_PRICE);
}

bool Test_ThreeRow_toString() {
  ThreeRow threeRow(6);
  std::string expected = "{\n\"class\": \"ThreeRow\",\n\"health\": " +
                         std::to_string(THREE_ROW_HEALTH) + ",\n\"level\": 6}";
  return threeRow.toString() == expected;
}

bool Test_ThreeRow_attack() {
  ThreeRow threeRow(6);
  DamageBullet *damage = threeRow.attack();
  bool testPassed =
      (damage != nullptr) &&
      (damage->getDamage() ==
       (THREE_ROW_POWER + threeRow.getLevel() * THREE_ROW_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_ThreeRow_levelUp() {
  ThreeRow threeRow(6);
  threeRow.levelUp();
  bool testPassed =
      (threeRow.getLevel() == 7 &&
       threeRow.getHealth() == THREE_ROW_HEALTH + THREE_ROW_HEALTH_INCREASE);
  return testPassed;
}

bool Test_ThreeRow_getCost() {
  ThreeRow threeRow(6);
  return threeRow.getCost() == (THREE_ROW_PRICE * 0.75);
}

bool Test_ThreeRow_value() {
  ThreeRow threeRow(6);
  return threeRow.value() ==
         (threeRow.getCost() + threeRow.getLevel() * THREE_ROW_PRICE);
}

bool Test_SlowDown_toString() {
  SlowDown slowDown(8);
  std::string expected = "{\n\"class\": \"SlowDown\",\n\"health\": " +
                         std::to_string(SLOW_DOWN_HEALTH) + ",\n\"level\": 8}";
  return slowDown.toString() == expected;
}

bool Test_SlowDown_attack() {
  SlowDown slowDown(8);
  DamageSlow *damage = slowDown.attack();
  bool testPassed =
      (damage != nullptr) &&
      (damage->getDamage() ==
       (SLOW_DOWN_POWER + slowDown.getLevel() * SLOW_DOWN_POWER_INCREASE));
  delete damage;
  return testPassed;
}

bool Test_SlowDown_levelUp() {
  SlowDown slowDown(8);
  slowDown.levelUp();
  bool testPassed =
      (slowDown.getLevel() == 9 &&
       slowDown.getHealth() == SLOW_DOWN_HEALTH + SLOW_DOWN_HEALTH_INCREASE);
  return testPassed;
}

bool Test_SlowDown_getCost() {
  SlowDown slowDown(8);
  return slowDown.getCost() == (SLOW_DOWN_PRICE * 0.75);
}

bool Test_SlowDown_value() {
  SlowDown slowDown(8);
  return slowDown.value() ==
         (slowDown.getCost() + slowDown.getLevel() * SLOW_DOWN_PRICE);
}
