#include "damage.h"

/// BulletDamage
DamageBullet::DamageBullet(u32 damage) : damage(damage) {}

u32 DamageBullet::getDamage() const { return damage; }

void DamageBullet::accept(VisitorGUI *visitor) const {
  visitor->visitDamageBullet();
}

DamageBullet *DamageBullet::clone() const { return new DamageBullet(*this); }

/// SlowDamage
DamageSlow::DamageSlow(u32 damage, u32 slow) : damage(damage), slow(slow) {}

u32 DamageSlow::getDamage() const { return damage; }

bool DamageSlow::getSlow() { return slow-- > 0; }

void DamageSlow::accept(VisitorGUI *visitor) const {
  visitor->visitDamageSlow();
}

DamageSlow *DamageSlow::clone() const { return new DamageSlow(*this); }

/// WaveDamage
DamageWave::DamageWave(u32 wave) : wave(wave), persistance(4) {}

u32 DamageWave::getDamage() const { return wave; }

bool DamageWave::oneWave() { return persistance-- > 0; }

void DamageWave::accept(VisitorGUI *visitor) const {
  visitor->visitDamageWave();
}

DamageWave *DamageWave::clone() const { return new DamageWave(*this); }

/// RobotDamage
DamageRobot::DamageRobot(u32 damage) : damage(damage) {}

u32 DamageRobot::getDamage() const { return damage; }

void DamageRobot::accept(VisitorGUI *visitor) const {
  visitor->visitDamageRobot();
}

DamageRobot *DamageRobot::clone() const { return new DamageRobot(*this); }
