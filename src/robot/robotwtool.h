#pragma once
#include "robot.cpp"
#include "tool.cpp"

class RobotWTool : public Robot, public Tool {
private:
  u32 attack() const override; // I don't want this to be useble
  u32 move() const override;   // I don't want this to be useble
public:
  RobotWTool(u32 = 0, u32 = 0);
  u32 attack() override;
  bool takeDamage(u32 &) override;
  u32 move() override;
};
