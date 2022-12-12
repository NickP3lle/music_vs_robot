#ifndef CHARACTER_H
#define CHARACTER_H
class character {
	public:
		int life, damage;
		character(int, int);
		virtual void attack() const =0;
		virtual void take_damage() =0;
};
#endif
