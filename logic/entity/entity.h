#pragma once
#include "../include.h"
#include "damage.h"

class EntityAbstract : public AcceptGUI, public Cloneable {
public:
  virtual u32 &getHealth() = 0;
  virtual bool sufferDamage(DamageAbstract *damage);
  // this might be a nullptr: DoubleLife
  virtual DamageAbstract *attack() const = 0;
};
