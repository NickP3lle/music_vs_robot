#include "robot.h"
#include <cstdlib>
#include <ctime>
#define u32 unsigned int

u32 get_rand(u32 max) {
	return 10;
}

void robot::tool::destroyed() const {
	cash::in(cash);
}

robot::tool::tool(u32 l, u32 d, u32 s, u32 c): 
	entity(l, d), speed(s), cash(c) {};

u32 robot::tool::attack() const {
	return damage;
}
