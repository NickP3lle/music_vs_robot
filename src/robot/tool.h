#include "../entity.h"
#include <vector>
#include "../cash.h"
#define u32 unsigned int

#ifndef TOOL_H
#define TOOL_H
class tool {
	public:
		virtual u32 move() const =0;
		virtual bool take_damage(u32&);
		virtual u32 attack() const;
};

class sword: public tool {
	private:
		u32 damage;
	public:
		sword(u32 d): damage(d) {};
		bool take_damage(u32&) override;
		u32 attack() const override;
		u32 move() const override;
};

class shield: public tool {
	private:
		u32 life;
	public:
		shield(u32 l): life(l) {};
		bool take_damage(u32&) override; 
		u32 attack() const override;
		u32 move() const override;
};

class ring: public tool {
	private:
		u32 life, cash;
	public:
		ring(u32 l, u32 c): life(l), cash(c) {};
		bool take_damage(u32&) override; 
		u32 attack() const override;
		u32 move() const override;
};

class bike: public tool {
	private:
		u32 life, speed;
	public:
		bike(u32 l, u32 s): life(l), speed(s) {};
		bool take_damage(u32&) override; 
		u32 attack() const override;
		u32 move() const override;
};
#endif
