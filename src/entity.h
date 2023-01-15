#ifndef ENTITY_H
#define ENTITY_H
#include "cash.h"

class Entity {
public:
  virtual ~Entity() = default;
  virtual bool takeDamage(u32 &amount) = 0;
  virtual u32 attack() const = 0;
  virtual Entity *clone() const = 0;
};
#endif
