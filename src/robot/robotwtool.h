#ifndef ROBOTWTOOL_H
#define ROBOTWTOOL_H

#include "../include.h"
#include "robot.h"
#include "tool.h"

class RobotWTool {
private:
	ptr<Robot> robot;
	ptr<Tool> tool;
public:
  RobotWTool(u32 = 0, u32 = 0);
  u32 attack();
  bool takeDamage(u32 &);
  u32 move();
};

#endif
