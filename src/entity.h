#ifndef ENTITY_H
#define ENTITY_H
class entity {
	private:
		virtual void destroyed() const =0;
	protected:
		unsigned int life, damage;
	public:
		entity(int, int);
		virtual unsigned int attack() const =0;
		virtual bool take_damage(unsigned int&) final; // non è modificabile
};
#endif
