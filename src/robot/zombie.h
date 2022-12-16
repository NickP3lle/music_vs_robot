#include <iostream>

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "creature.h"
class Zombie : public Creature {
	public:
		Zombie();
		virtual ~Zombie();
		void attack() override;
		void takeDamage(int damage) override;
		unsigned int move() override;
	private:
		unsigned int health;
		unsigned int attackPower;
};
#endif
