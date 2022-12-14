#include "robot.h"

robot::robot(const std::vector<u32>& i):
	entity(i[0], i[1]), weapon(new_tool(i[4]%5)), speed(i[2]), cash(i[3]) {};
	
void robot::destroyed() const {
	cash::in(cash * dcash);
}

u32 robot::attack() const {
	return ((weapon.isPtr()?weapon.get().attack():0)+damage)*ddamage;
}

u32 robot::move() const {
	return ((weapon.isPtr()?weapon.get().move():0)+speed)*dspeed;
}

bool robot::take_damage(unsigned int& d) {
	if (weapon.isPtr() && weapon.get_mut().take_damage(d)) {
		if (life > d) {
			life -= d;
			d = 0;
			return false;
		} else {
			d -= (life/dlife);
			destroyed();
			return true;
		}
	}
	return false;
}

// TODO: new_tool
//	dovrebbe tornare tool*
//
//	in più ogni volta che si copia un tool questo deve essere downcastato con
//	virtual
