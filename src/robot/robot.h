#include "../../util/ptr.h"
#include "../entity.h"
#include "../cash.h"
#include "tool.h"
#define u32 unsigned int

#ifndef ROBOT_H
#define ROBOT_H

class robot: private entity {
	private:
		u32 speed, cash, dlife, ddamage, dspeed, dcash;
		ptr<tool> weapon;

		void destroyed() const override;
	public:
		robot(const std::vector<u32>&);

		u32 attack() const override;
		bool take_damage(unsigned int&) override;
		u32 move() const;
};
#endif
