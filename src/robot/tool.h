#include "../../util/util.h"
#define u32 unsigned int

#ifndef TOOL_H
#define TOOL_H

/// every robot may have a Tool
class Tool {
private:
  u32 durability;

public:
  Tool(u32 max = 0, u32 min = 0);
  virtual u32 move() const;
  virtual bool takeDamage(u32 &);
  virtual u32 attack() const;
};

/// increase the attack of the robot which has it
class Weapon : public Tool {
private:
  u32 power;

public:
  Weapon(u32 = 0, u32 = 0);
  u32 attack() const override;
};

/// increase robot's speed by speed
class Speed : public Tool {
private:
  u32 s;

public:
  Speed(u32 = 0, u32 = 0);
  u32 move() const override;
};

///	prevent every damage to the robot durability times
class Shield : public Tool {
public:
  Shield(u32 = 0, u32 = 0);
  bool takeDamage(u32 &) override;
};

/*
/// after durability times, that the robot is attacked, the ring
/// drops value money
class Ring : public Tool {
private:
  u32 value;

public:
  Ring(u32 = 0, u32 = 0);
  virtual bool takeDamage(u32 &) override;
};
*/
#endif
