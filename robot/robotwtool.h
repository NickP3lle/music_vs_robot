#ifndef ROBOTWTOOL_H
#define ROBOTWTOOL_H

#include "robot.h"
#include "tool.h"
#include <memory>

class RobotWTool {
private:
  Robot *robot;
  Tool *tool;
  static Robot *randomRobot(u32, u32);
  static Tool *randomTool(u32, u32);

public:
  RobotWTool(u32, u32);
  RobotWTool() = delete;
  RobotWTool(const RobotWTool &);
  RobotWTool &operator=(const RobotWTool &);
  ~RobotWTool();
  u32 attack();
  bool takeDamage(u32 &);
  u32 move();
  Robot *getRobot() const;
  bool isAlive() const;
};

#endif
