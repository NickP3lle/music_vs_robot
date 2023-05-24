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
    Entity(u32 health, u32 power);
    u32 &getHealth();
    u32 &getPower();
    virtual u32 attack() const = 0;
    virtual Entity *clone() const = 0;
};
#endif
