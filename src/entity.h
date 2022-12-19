#include "cash.h"
#include "include.h"

#ifndef ENTITY_H
#define ENTITY_H
class Entity {
  private:
    u32 health;
    u32 power;

  protected:
    void updateHealth(u32 newHealth);        // replaices with the new life
    void updatePower(u32 powerIncrease = 0); // increment the power

  public:
    Entity(u32 health, u32 power);
    virtual bool takeDamage(u32 &amount) = 0;
    virtual u32 attack() const = 0;
};
#endif
