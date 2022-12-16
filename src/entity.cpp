#include "entity.h"

entity::entity(int l, int d):
	health(l), power(d) {};

bool entity::take_damage(unsigned int& d) {
	if (health > d) {
		health -= d;
		d = 0;
		return false;
	}
	else {
		d -= health;
		destroyed();
		return true;
	}
}
