#include "../entity.h"
#include "tool.h"

#ifndef ROBOT_H
#define ROBOT_H

/// il costruttore di un Robot generico prende 5 naturali:
///		health e power (ereditati dalla classe entity)
///		speed e value (dovrebbero essere in comune a tutti i Robot)
///		weapon (il naturale rappresenta la difficoltà)

class Robot : public Entity {
private:
  u32 speed, value;
  ptr<Tool> good;

protected:
  static bool tmp;

public:
  Robot(u32, u32 = 0);
  u32 attack() const override;
  bool takeDamage(u32 &amount) override;
  virtual u32 move() const;
};

class FastRobot : public Robot {
private:
  bool sprint;

public:
  FastRobot(u32, u32 =0);
  u32 move() const override;
};

class DefenseRobot : public Robot {
public:
  DefenseRobot(u32, u32 =0);
  bool takeDamage(u32 &) override;
};

// questo può essere un robot
// per cui il costruttore prende value*2
class RichRobot : public Robot {
public:
  RichRobot(u32, u32 =0);
  bool takeDamage(u32 &) override;
};

class BigRobot : public Robot {
public:
  BigRobot(u32, u32 =0);
  u32 move() const override;
};
#endif
