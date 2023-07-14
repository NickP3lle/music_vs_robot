#include "damage.h"

/// Damage
Damage::Damage(u32 damage) : d(damage) {}

u32 &Damage::getDamage() { return d; }

/// BulletDamage
DamageBullet::DamageBullet(u32 damage) : Damage(damage) {}

void DamageBullet::accept(VisitorGUI *visitor) const {
  visitor->visitDamageBullet();
}

DamageBullet *DamageBullet::clone() const { return new DamageBullet(*this); }

/// SlowDamage
DamageSlow::DamageSlow(u32 damage, u32 slow) : Damage(damage), slow(slow) {}

bool DamageSlow::getSlow() { return slow-- > 0; }

void DamageSlow::accept(VisitorGUI *visitor) const {
  visitor->visitDamageSlow();
}

DamageSlow *DamageSlow::clone() const { return new DamageSlow(*this); }

/// WaveDamage
DamageWave::DamageWave(u32 wave) : Damage(wave), persistance(4) {}

bool DamageWave::oneWave() { return persistance-- > 0; }

void DamageWave::accept(VisitorGUI *visitor) const {
  visitor->visitDamageWave();
}

DamageWave *DamageWave::clone() const { return new DamageWave(*this); }

/// RobotDamage
DamageEnemy::DamageEnemy(u32 damage) : Damage(damage) {}

void DamageEnemy::accept(VisitorGUI *visitor) const {
  visitor->visitDamageEnemy();
}

DamageRobot *DamageRobot::clone() const { return new DamageRobot(*this); }
