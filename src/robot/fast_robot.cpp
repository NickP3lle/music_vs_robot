#include "robot.h"

fast_robot::fast_robot(u32 d): 
	robot(d), sprint(true) {}

u32 fast_robot::move() const {
	return robot::move() / 2 * 3;
}

defense_robot::defense_robot(u32 d):
	robot(d) {}

bool defense_robot::take_damage(u32& damage) {
	damage /= 2;
	return robot::take_damage(damage);
}

rich_robot::rich_robot(u32 d):
	robot(d) {}

big_robot::big_robot(u32 d):
	robot({
			random_int(d),
			random_int(d),
			random_int(d),
			random_int(d*2),
			random_int(d*2)
		}) {}

void big_robot::destroyed() const {
	Cash::getInstance()->Cash::add(value*2);
}

u32 big_robot::move() const {
	return robot::move() / 2;
}

u32 big_robot::attack() const {
	return robot::attack() * 2;
}

bool big_robot::take_damage(u32& damage) {
	if (health > damage/2) {
		health = damage/2;
		damage = 0;
		return false;
	} else {
		damage -= health * 2;
		health = 0;
		return true;
	}
}
