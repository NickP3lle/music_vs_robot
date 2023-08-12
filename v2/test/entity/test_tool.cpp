#include "test_tool.h"

bool Test_Tool_isBroken() {
  u32 value = randomInt(100);
  Tool tool(value);
  if (tool.isBroken()) {
    return false;
  }
  return true;
}

bool Test_Tool_attack() {
  Tool tool(5);
  if (tool.attack() != 0) {
    return false;
  }

  return true;
}

bool Test_Tool_move() {
  Tool tool(5);
  if (tool.move() != 0) {
    return false;
  }

  return true;
}

bool Test_Tool_value() {
  Tool tool(5);
  if (tool.value() != 0) {
    return false;
  }

  return true;
}

bool Test_ToolWeapon_attack() {
  ToolWeapon tool(2, 5);
  if (tool.attack() == 0) {
    return false;
  }

  return true;
}

bool Test_ToolWeapon_sufferDamage() {
  ToolWeapon tool(2, 5);
  if (tool.sufferDamage(nullptr)) {
    return false;
  }

  return true;
}

bool Test_ToolArmor_sufferDamage() {
  ToolArmor tool(5);
  DamagePlayer damage(5, 0, 0);
  tool.sufferDamage(&damage);
  if (damage.damage() != 0)
    return false;

  return true;
}

bool Test_ToolBoots_sufferDamage() {
  ToolBoots tool(10);
  if (tool.sufferDamage(nullptr)) {
    return false;
  }

  return true;
}

bool Test_ToolBoots_move() {
  ToolBoots tool(10);
  if (tool.move() < 1) {
    return false;
  }

  return true;
}

bool Test_ToolRing_valueInRange() {
  ToolRing tool(10);
  u32 value = tool.value();
  if (value < 5 || value > 10) {
    return false;
  }

  return true;
}
