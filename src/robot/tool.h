#ifndef TOOL_H
#define TOOL_H
#include "../../util/util.h"

class Tool {
private:
  short int durability;

public:
  Tool(int = 0);
  bool isBroken() const;
  virtual u32 attack();
  virtual bool takeDamage(u32 &);
  virtual u32 move();
  virtual u32 value();
};

class Weapon : public Tool {
private:
  u32 damage;

public:
  Weapon(u32, u32);
  u32 attack() override;
  bool takeDamage(u32 &) override;
  // u32 move()  not overriden
  // u32 value() not overriden
};

class Armor : public Tool {
public:
  Armor(u32);
  // u32 attack() not overriden
  bool takeDamage(u32 &) override;
  // u32 move() not overriden
  // u32 value() not overriden
};

class Boots : public Tool {
private:
  u32 speed;

public:
  Boots(u32, u32);
  // u32 attack() not overriden
  bool takeDamage(u32 &) override;
  u32 move() override;
  // u32 value() not overriden
};

class Ring : public Tool {
private:
  u32 cash;

public:
  Ring(u32, u32);
  // u32 attack() not overriden
  // bool takeDamage(u32 &) overriden
  // u32 move() not overriden
  u32 value() override;
};

Tool randomTool(u32, u32);

#endif
