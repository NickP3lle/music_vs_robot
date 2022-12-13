#ifndef ENTITY_H
#define ENTITY_H
class entity {
	public:
		int life, damage;
		entity(int, int);
		virtual void attack() const =0;
		virtual void take_damage() =0;
};
#endif
