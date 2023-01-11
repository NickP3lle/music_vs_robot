#ifndef ROBOT_H
#define ROBOT_H
#include "../../util/util.h"
#include "../entity.h"

class Robot : public Entity {
private:
  u32 speed;
  u32 value;

public:
  bool takeDamage(u32 &) override;
  virtual Robot *clone() const override;
  Robot(u32 = 0, u32 = 0, bool = false, bool = false);
  virtual u32 move() const;
};

class DefenseRobot : public Robot {
public:
  bool takeDamage(u32 &) override;
  DefenseRobot *clone() const override;
  DefenseRobot(u32, u32 = 0);
};

class BigRobot : public Robot {
public:
  u32 move() const override;
  BigRobot *clone() const override;
  BigRobot(u32, u32 = 0);
};

Robot *randomRobot(u32, u32);

#endif
