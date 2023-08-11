#include "damage.h"

/// Damage
DamageAbstract::DamageAbstract(u32 damage) : d(damage) {}

u32 &DamageAbstract::getDamage() { return d; }

bool DamageAbstract::getSlow() { return false; }

/// BulletDamage
DamageBullet::DamageBullet(u32 damage) : DamageAbstract(damage) {}

void DamageBullet::accept(VisitorInterface *visitor) const {
  visitor->visitDamageBullet();
}

DamageBullet *DamageBullet::clone() const { return new DamageBullet(*this); }

/// SlowDamage
DamageSlow::DamageSlow(u32 damage, u32 slow)
    : DamageAbstract(damage), slow(slow) {}

bool DamageSlow::getSlow() {
  if (slow > 0)
    return false;
  slow--;
  return true;
}

void DamageSlow::accept(VisitorInterface *visitor) const {
  visitor->visitDamageSlow();
}

DamageSlow *DamageSlow::clone() const { return new DamageSlow(*this); }

/*
 *  DamageAbstract *DamageSlow::clone() const {
 *    u32 d = const_cast<DamageSlow *>(this)->getDamage();
 *    if (slow > 0)
 *      return new DamageSlow(d, slow);
 *     return new DamageBullet(d);
 *  }
 */

/// WaveDamage
DamageWave::DamageWave(u32 wave) : DamageAbstract(wave), persistance(4) {}

bool DamageWave::oneWave() { return persistance-- > 0; }

void DamageWave::accept(VisitorInterface *visitor) const {
  visitor->visitDamageWave();
}

DamageWave *DamageWave::clone() const { return new DamageWave(*this); }

/// RobotDamage
DamageEnemy::DamageEnemy(u32 damage) : DamageAbstract(damage) {}

void DamageEnemy::accept(VisitorInterface *visitor) const {
  visitor->visitDamageEnemy();
}

DamageEnemy *DamageEnemy::clone() const { return new DamageEnemy(*this); }
