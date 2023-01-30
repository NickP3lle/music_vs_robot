#ifndef ENTITY_H
#define ENTITY_H
#include "cash.h"

class Entity {
private:
  u32 health;
  u32 power;

public:
  virtual ~Entity() = default;
  virtual bool takeDamage(u32 &amount) = 0;
  Entity(u32 health, u32 power) : health(health), power(power) {}
  u32 &getHealth() { return health; }
  u32 &getPower() { return power; }
  virtual u32 attack() const = 0;
  virtual Entity *clone() const = 0;
};
#endif
