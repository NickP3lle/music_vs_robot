#include "tool.h"

bool sword::take_damage(u32&) { 
	return false; 
}

u32 sword::attack() const { 
	return damage; 
}

u32 sword::move() const { 
	return 0; 
}

bool shield::take_damage(u32& d) {
	if (life > d) {
		life -= d;
		d = 0;
		return false;
	} else {
		life = 0;
		d -= life;
		return true;
	}
};

u32 shield::attack() const { 
	return 0; 
}

u32 shield::move() const { 
	return 0; 
}

bool ring::take_damage(u32& d) {
	if (life > d) {
		life -= d;
		d = 0;
		return false;
	} else {
		life = 0;
		d -= life;
		cash::in(cash);
		return true;
	}
};

u32 ring::attack() const { 
	return 0; 
}

u32 ring::move() const { 
	return 0; 
}

bool bike::take_damage(u32& d) {
	if (life > d) {
		life -= d;
		d = 0;
		return false;
	} else {
		life = 0;
		d -= life;
		return true;
	}
};

u32 bike::attack() const { 
	return 0; 
}

u32 bike::move() const { 
	return speed; 
}
