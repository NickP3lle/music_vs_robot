#ifndef ROBOTWTOOL_H
#define ROBOTWTOOL_H

#include "robot.h"
#include "tool.h"
#include <memory>

class RobotWTool {
private:
  std::shared_ptr<Robot> robot;
  std::shared_ptr<Tool> tool;
  static Robot *randomRobot(u32, u32);
  static Tool *randomTool(u32, u32);

public:
  RobotWTool(u32, u32);
  RobotWTool();
  u32 attack();
  bool takeDamage(u32 &);
  u32 move();
  Robot *getRobot() const;
  bool isAlive() const;
};

#endif
