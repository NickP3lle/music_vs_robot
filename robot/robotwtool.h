#ifndef ROBOTWTOOL_H
#define ROBOTWTOOL_H

#include "robot.h"
#include "tool.h"
#include <memory>
#define ptr_robot std::unique_ptr<Robot>
#define ptr_tool std::unique_ptr<Tool>

class RobotWTool : public DataManagerInterface {
private:
  ptr_robot robot;
  ptr_tool tool;
  static Robot *randomRobot(u32, u32);
  static Tool *randomTool(u32, u32);

public:
  RobotWTool(u32, u32);
  RobotWTool();
  RobotWTool(const RobotWTool &);
  RobotWTool &operator=(const RobotWTool &);
  u32 attack();
  bool takeDamage(u32 &);
  u32 move();
  Robot *getRobot() const;
  bool isAlive() const;

  virtual std::string saveData() override;
};

#endif
