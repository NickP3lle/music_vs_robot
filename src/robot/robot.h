#ifndef ROBOT_H
#define ROBOT_H
#include "../../util/util.h"
#include "../entity.h"

class Robot : public Entity {
private:
  u32 health;
  u32 power;
  u32 value;
  u32 speed;

public:
  Robot(u32 = 0, u32 = 0, bool = false, bool = false);
  bool takeDamage(u32 &) override;
  u32 attack() const override final;
  virtual Robot *clone() const override;
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

#endif
