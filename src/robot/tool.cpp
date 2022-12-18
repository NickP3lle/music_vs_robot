#include "Tool.h"
#define DURABILITY 100

//	every item can be used only durability times

Tool::Tool(u32 max, u32 min) : durability(random_int(max, min)) {}

u32 Tool::move() const { return 0; }

bool Tool::takeDamage(u32 &d) { return --d; }

u32 Tool::attack() const { return 0; }

//	improve robot attack

weapon::weapon(u32 max, u32 min)
    : Tool(max, min), power(random_int(max, min)) {}

u32 weapon::attack() const { return power; }

//	saves the robot durability times

shield::shield(u32 max, u32 min) : Tool(max, min) {}

bool shield::takeDamage(u32 &d) {
  d = 0;
  return Tool::takeDamage(d);
}

//	make the robot faster

speed::speed(u32 d, u32 velocity) : Tool(d), s(velocity) {}

u32 speed::move() const { return s; }

//	drops more money

ring::ring(u32 v, u32 d) : Tool(d), value(v) {}
