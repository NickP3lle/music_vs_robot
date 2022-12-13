#include "entity.h"

entity::entity(int l, int d):
	life(l), damage(d) {};

bool entity::take_damage(unsigned int& d) {
	if (life > d) {
		life -= d;
		d = 0;
		return false;
	}
	else {
		d -= life;
		destroyed();
		return true;
	}
}
