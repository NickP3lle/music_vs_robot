#include "../../../util/util.h"
#include "testTool.cpp"
#include "testRobot.cpp"

int main() {
  // test Robot
  Test("RobotInit", TestRobotInit);
  Test("RobotAttack", TestRobotAttack);
  Test("RobotMove", TestRobotMove);
  
  Test("DefenseRobotTakeDamage", TestDefenseRobotTakeDamage);
  Test("BigRobotInit", TestBigRobotInit);
	
  Test("RandomRobot", TestRandomRobot);

  Test("WeaponInit", TestWeaponInit);
  Test("WeaponAttack", TestWeaponAttack);
  Test("WeaponTakeDamage", TestWeaponTakeDamage);
  Test("ArmorInit", TestArmorInit);
  Test("ArmorTakeDamage", TestArmorTakeDamage);
  Test("BootsInit", TestBootsInit);
  Test("BootsMove", TestBootsMove);
  Test("BootsTakeDamage", TestBootsTakeDamage);
  Test("RingInit", TestRingInit);
  Test("RingValue", TestRingValue);
  Test("RingTakeDamage", TestRingTakeDamage);
  Test("RandomTool", TestRandomTool);

  Test("RobotWToolInit", TestRobotWToolInit);
  Test("RobotWToolAttack", TestRobotWToolAttack);
  return 0;
}
