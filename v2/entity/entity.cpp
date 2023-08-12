#include "entity.h"

bool EntityAbstract::sufferDamage(DamageAbstract *d) {
  u32 damage = d->damage();
  if (getHealth() > damage) {
    getHealth() -= damage;
    return false;
  } else {
    getHealth() = 0;
    return true;
  }
}
