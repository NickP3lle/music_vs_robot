#include "../../util/ptr.h"
#include "../entity.h"
#include "../cash.h"
#include "tool.h"
#define u32 unsigned int

#ifndef ROBOT_H
#define ROBOT_H

/// il costruttore di un Robot generico prende 5 naturali:
///		health e power (ereditati dalla classe entity)
///		speed e value (dovrebbero essere in comune a tutti i Robot)
///		weapon (il naturale rappresenta la difficoltà)

class Robot: public Entity {
	protected:
		u32 speed, value;
		ptr<Tool> good;

		void destroyed() const;
		Robot(const std::vector<u32>&);
	public:
		Robot(u32);
		u32 attack() const override;
		bool takeDamage(u32 &amount) override;
		virtual u32 move() const;
};

class FastRobot: public Robot {
	private:
		bool sprint;
	public:
		FastRobot(u32);
		u32 move() const override;
};

class DefenseRobot: public Robot {
	public:
		DefenseRobot(u32);
		bool takeDamage(u32&) override;
};

class RichRobot: public Robot {
	private:
		void destroyed() const;
	public:
		RichRobot(u32);
};

class BigRobot: public Robot {
	private:
		void destroyed() const;
	public:
		BigRobot(u32);
		u32 move() const override;
		u32 attack() const override;
		bool takeDamage(u32&) override;
};
#endif
