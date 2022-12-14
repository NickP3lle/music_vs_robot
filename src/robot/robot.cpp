#include "robot.h"

///	definisco i metodi della classe innestata tool

void robot::tool::destroyed() const {
	cash::in(cash);
}

//	vettore grande 5:
//	life, damage, speed, cash
robot::tool::tool(std::vector<u32> i): 
	entity(i[0], i[1]), speed(i[3]), cash(i[4]) {};

u32 robot::tool::attack() const {
	return damage;
}

// genera 4 numeri casuali in base alla difficoltà passata
robot::tool robot::tool::New(u32 difficulty) {
	std::vector<u32> tmp(0, 4);
	for (int i=0; i<=difficulty%100 && i<4; i++)
		tmp[i] = rand()%difficulty;
	return robot::tool(tmp);
}

/// definisco i metodi propri della classe robot
robot::robot(const std::vector<u32>& i):
	entity(i[0], i[1]), weapon(tool::New(i[4]%5)), speed(i[2]), cash(i[3]) {};
	
void robot::destroyed() const {
	cash::in(cash);
}

u32 robot::attack() const {
	return (weapon.isPtr()?weapon.get().damage:0)+damage; 
}

u32 robot::move() const {
	return (weapon.isPtr()?weapon.get().speed:0)+speed; 
}

bool robot::take_damage(unsigned int& d) {
	if (weapon.isPtr() && weapon.get_mut().take_damage(d)) {
		if (life > d) {
			life -= d;
			d = 0;
			return false;
		} else {
			d -= life;
			destroyed();
			return true;
		}
	}
	return false;
}
