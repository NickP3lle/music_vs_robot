#include "entity.h"

bool EntityAbstract::sufferDamage(DamageAbstract *d) {
  if (getHealth() > d->getDamage()) {
    getHealth() -= d->getDamage();
    return false;
  } else {
    getHealth() = 0;
    return true;
  }
}
