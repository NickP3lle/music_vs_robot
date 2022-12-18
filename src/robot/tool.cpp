#include "tool.h"
#define DURABILITY 100

//	every item can be used only durability times

Tool::Tool(u32 max, u32 min) : durability(random_int(max, min)) {}

u32 Tool::move() const { return 0; }

bool Tool::takeDamage(u32 &d) { return --d; }

u32 Tool::attack() const { return 0; }

//	improve robot attack

Weapon::Weapon(u32 max, u32 min)
    : Tool(max, min), power(random_int(max, (max - min) / 2)) {}

u32 Weapon::attack() const { return power; }

//	make the robot faster

Speed::Speed(u32 max, u32 min) : Tool(max, min), s(random_int(max, min)) {}

u32 Speed::move() const { return s; }

//	saves the robot durability times

Shield::Shield(u32 max, u32 min) : Tool(max, min) {}

bool Shield::takeDamage(u32 &d) {
  d = 0;
  return Tool::takeDamage(d);
}

//	drops more money

// Ring::Ring(u32 max, u32 min) : Tool(max, min), value(random_int(max, min)) {}
