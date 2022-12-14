#ifndef ENTITY_H
#define ENTITY_H
class entity {
	protected:
		unsigned int life, damage;
	public:
		virtual void destroyed() const =0;
		entity(int, int);
		virtual unsigned int attack() const =0;
		virtual bool take_damage(unsigned int&);
};
#endif
