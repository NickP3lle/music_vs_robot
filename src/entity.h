#ifndef ENTITY_H
#define ENTITY_H
class entity {
	public:
		virtual void destroyed() const =0;
		unsigned int life, damage;
		entity(int, int);
		virtual unsigned int attack() const =0;
		virtual bool take_damage(unsigned int&);
};
#endif
