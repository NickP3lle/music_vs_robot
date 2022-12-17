<<<<<<< HEAD
#pragma once
#include "cash.h"
#include <iostream>
>>>>>>> 7d25560f2e8b4b6d0050ebd0058e5350f41596e6

#include <vector>
//#ifndef ENTITY_H
//#define ENTITY_H
class Entity {
  private:
    u32 health;
    u32 power;

  protected:
    void updateHealth(u32 healthGain = 0);
    void updatePower(u32 powerIncrease = 0);

  public:
    Entity(u32 health, u32 power);
    virtual bool takeDamage(u32 &amount) = 0;
    virtual u32 attack() const = 0;
};
//#endif

