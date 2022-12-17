#include "../cash.h"

#ifndef TOOL_H
#define TOOL_H

/// every robot may have a Tool
class Tool {
protected:
  u32 durability;
  Tool(u32 = 0);

public:
  virtual u32 move() const;
  virtual bool takeDamage(u32 &);
  virtual u32 attack() const;
};

/// increase the attack of the robot which has it
class weapon : public Tool {
private:
  u32 power;

public:
  weapon(u32, u32);
  virtual u32 attack() const;
};

/// increase robot's speed by speed
class speed : public Tool {
private:
  u32 s;

public:
  speed(u32, u32);
  u32 move() const override;
};

///	prevent every damage to the robot durability times
class shield : public Tool {
public:
  shield(u32);
  virtual bool takeDamage(u32 &) override;
};

/// after durability times, that the robot is attacked, the ring
/// drops value money
class ring : public Tool {
private:
  u32 value;

public:
  ring(u32, u32);
  virtual bool takeDamage(u32 &) override;
};
#endif
