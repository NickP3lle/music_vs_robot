#pragma once
#include "../entity.cpp"
#include "../include.h"

// Class: Robot
// has two u32 variables: speed and value
// has a polimorphic function: move

class Robot : public Entity {
private:
  u32 speed;
  u32 value;
  // ptr<Tool> tool;
public:
  u32 attack() const override;
  bool takeDamage(u32 &) override;
  Robot(u32 = 0, u32 = 0, bool = false, bool = false);
  virtual u32 move() const;
};

class DefenseRobot : public Robot {
public:
  DefenseRobot(u32, u32 = 0);
  bool takeDamage(u32 &) override;
};

class BigRobot : public Robot {
public:
  BigRobot(u32, u32 = 0);
  u32 move() const override;
};

Robot randomRobot(u32, u32);
