#ifndef CREATURE_H
#define CREATURE_H

class Creature {
	public:
		Creature();
		virtual ~Creature();
		virtual void attack() = 0;
		virtual void takeDamage(int damage) = 0;
		virtual unsigned int move() = 0;
	private:
		unsigned int health;
		unsigned int attackPower;
};
#endif
