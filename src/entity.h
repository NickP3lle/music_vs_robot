#define u32 unsigned int

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
	private:
		u32 health;
		u32 power;
	public:
		Entity(u32 health, u32 power);
		virtual bool take_damage(u32& amount) =0;
//		virtual void heal(u32 amount) =0;
		virtual u32 attack() const =0;
};
#endif
