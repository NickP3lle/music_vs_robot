#include "../../util/ptr.h"
#include "../entity.h"
#include "../cash.h"
#include "tool.h"
#define u32 unsigned int

#ifndef ROBOT_H
#define ROBOT_H

/// il costruttore di un robot generico prende 5 naturali:
///		health e power (ereditati dalla classe entity)
///		speed e value (dovrebbero essere in comune a tutti i robot)
///		weapon (il naturale rappresenta la difficoltà)

class robot: public Entity {
	protected:
		u32 speed, value;
		ptr<tool> good;

		void destroyed() const;
		robot(const std::vector<u32>&);
	public:
		robot(u32);
		u32 attack() const override;
		bool take_damage(u32&) override;
		virtual u32 move() const;
};

class fast_robot: public robot {
	private:
		bool sprint;
	public:
		fast_robot(u32);
		u32 move() const override;
};

class defense_robot: public robot {
	public:
		defense_robot(u32);
		bool take_damage(u32&) override;
};

class rich_robot: public robot {
	private:
		void destroyed() const override;
	public:
		rich_robot(u32);
};

class big_robot: public robot {
	private:
		void destroyed() const override;
	public:
		big_robot(u32);
		u32 move() const override;
		u32 attack() const override;
		bool take_damage(u32&) override;
};
#endif
