#include "main.h"

int main() {
  // test Robot
  Test("RobotAttack", TestRobotAttack);
  Test("RobotMove", TestRobotMove);

  Test("DefenseRobotTakeDamage", TestDefenseRobotTakeDamage);
  Test("BigRobot", TestBigRobotInit);

  Test("WeaponAttack", TestWeaponAttack);
  Test("WeaponTakeDamage", TestWeaponTakeDamage);
  Test("ArmorTakeDamage", TestArmorTakeDamage);
  Test("BootsMove", TestBootsMove);
  Test("BootsTakeDamage", TestBootsTakeDamage);
  Test("RingValue", TestRingValue);
  Test("RingTakeDamage", TestRingTakeDamage);

  Test("RobotWToolAttack", TestRobotWToolAttack);
  return 0;
}
