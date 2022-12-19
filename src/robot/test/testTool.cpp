#include "../tool.cpp"

/// failed weapon: takeDamage and attack
/// failed boots: takeDamage
/// failed ring: takeDamage
/// failed createRandomTool

bool TestWeaponInit() {
  try {
    Weapon weapon(3, 1);
    if (weapon.isBroken())
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

bool TestWeaponAttack() {
  Weapon weapon(40, 35);
  tmp = weapon.attack();
  if (tmp < 35 || tmp > 40)
    return false;
  return true;
}

bool TestWeaponTakeDamage() {
  Weapon weapon(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (weapon.takeDamage(tmp))
      return false;
  return true;
}

bool TestArmorInit() {
  try {
    Armor armor(3, 1);
    if (armor.isBroken())
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

bool TestArmorTakeDamage() {
  Armor armor(3, 1);
  tmp = 1;
  armor.takeDamage(tmp);
  if (tmp != 0)
    return false;
  return true;
}

bool TestBootsInit() {
  try {
	Boots boots(3, 1);
	if (boots.isBroken())
	  return false;
  } catch (...) {
	return false;
  }
  return true;
}

bool TestBootsMove() {
  Boots boots(3, 1);
  tmp = boots.move();
  if (tmp < 1 || tmp > 3)
	return false;
  return true;
}

bool TestBootsTakeDamage() {
  Weapon boots(3, 1);
  for (tmp = 0; tmp < 5; tmp++)
    if (boots.takeDamage(tmp))
      return false;
  return true;
}

bool TestRingInit() {
  try {
	Ring ring(3, 1);
	if (ring.isBroken())
	  return false;
  } catch (...) {
	return false;
  }
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
		Tool tool = randomTool(tmp, tmp/2);
	return true;
}
