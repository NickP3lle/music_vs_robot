#include "tool.h"

Tool::Tool(int d) : durability(d > 0 ? (randomInt(d) % 5) + 1 : -1) {}

bool Tool::isBroken() const { return durability == 0; }

u32 Tool::attack() { return 0; }

bool Tool::sufferDamage(DamageAbstract &d) {
  if (durability < 0)
    return false;
  else if (durability > 0)
    durability--;
  return isBroken();
}

u32 Tool::move() { return 0; }

u32 Tool::value() const { return 0; }

Tool *Tool::clone() const { return new Tool(*this); }

void Tool::accept(VisitorInterface *v) const {}

ToolWeapon::ToolWeapon(u32 min, u32 max) : Tool(max), a(randomInt(max, min)) {}

u32 ToolWeapon::attack() {
  if (isBroken())
    return 0;
  DamagePlayer d(0, 0, 0);
  Tool::sufferDamage(d);
  return a;
}

bool ToolWeapon::sufferDamage(DamageAbstract &d) { return false; }

ToolWeapon *ToolWeapon::clone() const { return new ToolWeapon(*this); }

void ToolWeapon::accept(VisitorInterface *v) const { v->visitToolWeapon(); }

ToolArmor::ToolArmor(u32 max) : Tool(max) {}

bool ToolArmor::sufferDamage(DamageAbstract &d) {
  if (isBroken())
    return false;
  d / MAX_U32; // should be 0, at most it is 1
  return Tool::sufferDamage(d);
}

ToolArmor *ToolArmor::clone() const { return new ToolArmor(*this); }

void ToolArmor::accept(VisitorInterface *v) const { v->visitToolArmor(); }

ToolBoots::ToolBoots(u32 max)
    : Tool(max % 10), s(randomInt(ROBOT_MAX_SPEED, ROBOT_MIN_SPEED) / 2) {}

bool ToolBoots::sufferDamage(DamageAbstract &d) { return false; }

u32 ToolBoots::move() {
  if (isBroken())
    return 0;
  DamagePlayer d(0, 0, 0);
  Tool::sufferDamage(d);
  return s;
}

ToolBoots *ToolBoots::clone() const { return new ToolBoots(*this); }

void ToolBoots::accept(VisitorInterface *v) const { v->visitToolBoots(); }

ToolRing::ToolRing(u32 min) : Tool(0), v(randomInt(min / 2) + min / 2) {}

u32 ToolRing::value() const { return v; }

ToolRing *ToolRing::clone() const { return new ToolRing(*this); }

void ToolRing::accept(VisitorInterface *v) const { v->visitToolRing(); }
