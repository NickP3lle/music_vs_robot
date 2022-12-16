#define u32 unsigned int

#ifndef ENTITY_H
#define ENTITY_H
// class Entity:
// - represents an entity
// - both music_instrument and robot are entities
// - has a health and a power
// - can be damaged and healed
// - can attack other entities
// - can be destroyed
// - can be cloned
// - can be upgraded

class Entity {
	public:
		virtual void damage(u32 amount) =0;
		virtual void heal(u32 amount) =0;
		virtual void attack(Entity* entity) =0;
		virtual void destroy() =0;
		virtual Entity* clone() =0;
		virtual void upgrade() =0;
	protected:
		u32 health;
		u32 power;
};
#endif
