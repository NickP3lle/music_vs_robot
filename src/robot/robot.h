#ifndef ROBOT_H
#define ROBOT_H
#include "../../util/util.h"
#include "../entity.h"

class Robot : public Entity {
private:
  u32 speed;
  u32 value;

public:
  u32 attack() const override;
  bool takeDamage(u32 &) override;
  Robot(u32 = 0, u32 = 0, bool = false, bool = false);
  virtual u32 move() const;
  virtual Robot *clone() const;
};

class DefenseRobot : public Robot {
public:
  DefenseRobot(u32, u32 = 0);
  bool takeDamage(u32 &) override;
  DefenseRobot *clone() const override;
};

class BigRobot : public Robot {
public:
  BigRobot(u32, u32 = 0);
  u32 move() const override;
  BigRobot *clone() const override;
};

Robot *randomRobot(u32, u32);

#endif
