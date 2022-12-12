#include "../character.h"
#include "tool.h"

#ifndef ROBOT_H
#define ROBOT_H

class robot: public character {
	tool* weapon;
	unsigned int speed;
};

#endif
