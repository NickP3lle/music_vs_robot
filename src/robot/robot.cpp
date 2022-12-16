#include "robot.h"
// TODO: robot::robot(u32 d), forse va riscritto

namespace {
	ptr<tool> new_none(u32 d) {
		return ptr<tool>(nullptr);
	}

	ptr<tool> new_weapon(u32 d) {
		return ptr<tool>(weapon(random_int(d), random_int(d)));
	}

	ptr<tool> new_shield(u32 d) {
		return ptr<tool>(shield(random_int(d)));
	}

	ptr<tool> new_speed(u32 d) {
		return ptr<tool>(speed(random_int(d), random_int(d)));
	}

	ptr<tool> new_ring(u32 d) {
		return ptr<tool>(ring(random_int(d), random_int(d)));
	}

	ptr<tool> new_tool(u32 d) {
		switch (random_int(5)) {
			case 0: return new_none(d);
			case 1: return new_ring(d);
			case 2: return new_shield(d);
			case 3: return new_speed(d);
			default: return new_weapon(d);
		}
	}
}

robot::robot(const std::vector<u32>& i):
	entity(i[0], i[1]), 
	speed(i[2]), value(i[3]), 
	good(new_tool(i[4])) {}

robot::robot(u32 d):
	entity(random_int(d), random_int(d)), 
	speed(random_int(d)), value(random_int(d)), 
	good(new_tool(d)) {}

void robot::destroyed() const {
	cash::in(value);
}

ptr<robot> new_generic_robot(u32 d) {
	switch (random_int(4)) {
		case 0: return ptr<robot>(fast_robot(d));
		case 1: return ptr<robot>(defense_robot(d));
		case 2: return ptr<robot>(rich_robot(d));
		case 3: return ptr<robot>(big_robot(d));
		default: return ptr<robot>(robot(d));
	}
}

u32 robot::attack() const {
	return (good.isPtr()?good.get().attack():0)+power;
}

bool robot::take_damage(u32& d) {
	if (good.isPtr() && good.get_mut().take_damage(d))
		good.free();
	if (health>d) {
		health -= d;
		d = 0;
		return false;
	}
	else {
		d -= health;
		return false;
	}
}

u32 robot::move() const {
	return (good.isPtr()?good.get().move():0)+speed;
}
