#pragma once
#include "tool.h"

// cannot be bigger than 5, though it can be smaller
Tool::Tool(int d) : durability(d > 0 ? randomInt(d) % 5 + 1 : -1) {}

bool Tool::isBroken() const { return durability == 0; }

u32 Tool::attack() { return 0; }

bool Tool::takeDamage(u32 &damage) {
  if (durability > 1)
    durability--;
  return durability > 0;
}

u32 Tool::move() { return 0; }

u32 Tool::value() { return 0; }

Weapon::Weapon(u32 max, u32 min) : Tool(max), damage(randomInt(max, min)) {}

u32 Weapon::attack() {
  if (isBroken())
    return 0;
  Weapon::takeDamage(tmp);
  return damage;
}

bool Weapon::takeDamage(u32 &damage) { return false; }

Armor::Armor(u32 max) : Tool(max) {}

bool Armor::takeDamage(u32 &damage) {
  if (Tool::isBroken())
    return true;
  damage = 0;
  return Tool::takeDamage(damage);
}

Boots::Boots(u32 max, u32 min) : Tool(max % 10), speed(randomInt(max, min)) {}

bool Boots::takeDamage(u32 &damage) { return false; }

u32 Boots::move() {
  if (Tool::isBroken())
    return 0;
  Tool::takeDamage(speed);
  return speed;
}

Ring::Ring(u32 max, u32 min) : Tool(-1), cash(randomInt(max, min)) {}

u32 Ring::value() { return cash; }

// this function generate a random tool
Tool randomTool(u32 max, u32 min) {
  switch (randomInt(3)) {
  case 0:
    return Weapon(max, min);
  case 1:
    return Armor(max);
  case 2:
    return Boots(max, min);
  deault:
    return Ring(max, min);
  }
  return Tool(-1); // non oggetto
}
