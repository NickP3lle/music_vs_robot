#include "../entity.h"
#include "../cash.h"
#define u32 unsigned int

#ifndef ROBOT_H
#define ROBOT_H

enum hard {
	very_easy,
	easy,
	medium,
	hard,
	pro
};

class robot: public entity {
	private:
		class tool: public entity {
			private:
				virtual void destroyed() const override;
				tool(u32, u32, u32, u32);
			public:
				virtual u32 attack() const override;
				u32 speed, cash;
				static tool New(enum hard);
		};
		robot::tool weapon;
		unsigned int speed;
	public:
		robot(u32, u32, u32, u32);
};
#endif
