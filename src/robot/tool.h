#pragma once
#include "../include.h"

/*
 * class Tool
 * - class for all tools
 * - has 1 variable durability
 *   - durability is the amount of uses the tool has left
 *   - durability is 0 when the tool is broken
 *   - durability is -1 when the tool is infinite
 * has a virtual function attack() which return a u32
 * has a virtual function takeDamage(u32&) which returns a bool
 * has a virtual function move() which returns a u32
 */

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
private:
  u32 defense;

public:
  Armor(u32, u32);
  // u32 attack() not overriden
  bool takeDamage(u32 &);
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
