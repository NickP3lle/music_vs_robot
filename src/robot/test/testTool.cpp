#include "testTool.h"

bool TestWeaponAttack() {
  Weapon weapon(40, 40);
  tmp = weapon.attack();
  if (tmp != 40) {
    return false;
  }
  return true;
}
bool TestWeaponTakeDamage() {
  Weapon weapon(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (weapon.takeDamage(tmp))
      return false;
  return true;
}

bool TestArmorTakeDamage() {
  Armor armor(3);
  tmp = 1;
  armor.takeDamage(tmp);
  if (tmp != 0)
    return false;
  return true;
}

bool TestBootsMove() {
  for (int i = 0; i < 100; i++) {
    Boots boots(50, 50);
    tmp = boots.move();
    if (tmp != 50)
      return false;
  }
  return true;
}
bool TestBootsTakeDamage() {
  Weapon boots(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (boots.takeDamage(tmp))
      return false;
  return true;
}

bool TestRingValue() {
  Ring ring(3, 1);
  tmp = ring.value();
  if (tmp < 1 || tmp > 3)
    return false;
  return true;
}
bool TestRingTakeDamage() {
  Weapon ring(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (ring.takeDamage(tmp))
      return false;
  return true;
}

bool TestRandomTool() {
  for (int tmp = 50; tmp < 150; tmp++)
    Tool tool = randomTool(tmp, tmp / 2);
  return true;
}
