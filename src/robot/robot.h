#include <vector>
#include "../../util/ptr.h"
#include "../entity.h"
#include "../cash.h"
#include <stdlib.h>
#define u32 unsigned int

#ifndef ROBOT_H
#define ROBOT_H

class robot: private entity {
	private:
		class tool: public entity {
			public:
				virtual void destroyed() const override;
				tool(std::vector<u32>);
				virtual u32 attack() const override;
				static tool New(u32);
				u32 speed, cash;
		};

		ptr<robot::tool> weapon;
		unsigned int speed;
		unsigned int cash;

		void destroyed() const override;
	public:
		robot(const std::vector<u32>&);

		u32 attack() const override;
		bool take_damage(unsigned int&) override;
		virtual u32 move() const final;
};
#endif
