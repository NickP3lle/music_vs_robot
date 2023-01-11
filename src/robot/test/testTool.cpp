#include "main.h"

bool TestWeaponAttack() {
  u32 tmp;
  Weapon weapon(40, 40);
  tmp = weapon.attack();
  if (tmp != 40) {
    return false;
  }
  return true;
}
bool TestWeaponTakeDamage() {
  Weapon weapon(3, 1);
  u32 tmp;
  for (tmp = 0; tmp < 5; tmp++)
    if (weapon.takeDamage(tmp))
      return false;
  return true;
}

bool TestArmorTakeDamage() {
  u32 tmp;
  Armor armor(3);
  tmp = 1;
  armor.takeDamage(tmp);
  if (tmp != 0)
    return false;
  return true;
}

bool TestBootsMove() {
  u32 tmp;
  for (int i = 0; i < 100; i++) {
    Boots boots(50, 50);
    tmp = boots.move();
    if (tmp != 50)
      return false;
  }
  return true;
}
bool TestBootsTakeDamage() {
  u32 tmp;
  Weapon boots(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (boots.takeDamage(tmp))
      return false;
  return true;
}

bool TestRingValue() {
  u32 tmp;
  Ring ring(3, 1);
  tmp = ring.value();
  if (tmp < 1 || tmp > 3)
    return false;
  return true;
}
bool TestRingTakeDamage() {
  u32 tmp;
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
