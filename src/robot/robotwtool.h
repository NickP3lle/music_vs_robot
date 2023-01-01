#ifndef ROBOTWTOOL_H
#define ROBOTWTOOL_H
#include "tool.h"
#include "robot.h"

class RobotWTool {
private:
	ptr<Robot> robot;
	ptr<Tool> tool;
public:
  RobotWTool(u32, u32 = 0);
  RobotWTool();
  u32 attack();
  bool takeDamage(u32 &);
  u32 move();
};

#endif
