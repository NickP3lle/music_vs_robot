#ifndef ENTITY_H
#define ENTITY_H
#include "cash.h"

class Entity {
  private:
    u32 health;
    u32 power;

  protected:
    void updateHealth(u32 newHealth);        // replaces with the new life
    void updatePower(u32 powerIncrease = 0); // increment the power
    u32 getPower() const;
    Entity(u32 health, u32 power);

  public:
    virtual bool takeDamage(u32 &amount);
    virtual u32 attack() const = 0;
};
#endif
