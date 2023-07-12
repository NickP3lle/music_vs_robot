#pragma once
#include "damage.h"
#include "include.h"

class Entity : public AcceptGUI, public Cloneable {
private:
  u32 health;

public:
  Entity(u32 health);

  u32 &getHealth() const;
  virtual bool sufferDamage(Damage *damage) = 0;
  // this might be a nullptr: DoubleLife
  virtual Damage *attack() const = 0;
};
