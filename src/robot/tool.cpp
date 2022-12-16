#include "tool.h"
#define DURABILITY 100

//	every item can be used only durability times

tool::tool(u32 d): durability(d%DURABILITY) {}

tool tool::New(u32 difficulty) const {
	return tool();
}

u32 tool::move() const { return 0; }

bool tool::take_damage(u32& d) {
	return --d;
}

u32 tool::attack() const { return 0; }

//	improve robot attack

weapon::weapon(u32 d, u32 p): tool(d), power(p) {}

u32 weapon::attack() const { return power; }

//	saves the robot durability times

tool shield::New(u32 difficulty) const {
	return shield(random_int(difficulty));
}

shield::shield(u32 d): tool(d) {}

bool shield::take_damage(u32& d) {
	d = 0;
	return --durability;
}
	
//	make the robot faster

speed::speed(u32 d, u32 velocity): tool(d), s(velocity) {}

tool speed::New(u32 difficulty) const {
	return speed(random_int(difficulty), random_int(difficulty));
}

u32 speed::move() const {
	return s;
}

//	drops more money

tool ring::New(u32 difficulty) const {
	return ring(random_int(difficulty), random_int(difficulty));
}

ring::ring(u32 v, u32 d): tool(d), value(v) {}
