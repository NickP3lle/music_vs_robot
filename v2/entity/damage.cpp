#include "damage.h"

/// DamageBullet
DamageBullet::DamageBullet(u32 damage) : d(damage) {}

u32 &DamageBullet::damage() { return d; }

void DamageBullet::accept(VisitorInterface *visitor) const {
  visitor->visitDamageBullet();
}

/// DamageSlow
DamageSlow::DamageSlow(u32 slow) : s(slow) {}

u32 DamageSlow::getSlow() { return s; }

bool DamageSlow::slow() {
  std::cout << "slow: " << s << std::endl;
  if (s == 0)
    return false;
  s--;
  return true;
}

void DamageSlow::accept(VisitorInterface *visitor) const {
  visitor->visitDamageSlow();
}

/// DamageWave
DamageWave::DamageWave(u32 wave) : d(wave), p(4) {}

void DamageWave::oneWave() {
  if (--p < 1)
    d = 0;
}

u32 &DamageWave::damage() { return d; }

void DamageWave::accept(VisitorInterface *visitor) const {
  visitor->visitDamageWave();
}

/// DamagePlayer
DamagePlayer::DamagePlayer(u32 bd, u32 sd, u32 wd)
    : DamageBullet(bd), DamageSlow(sd), DamageWave(wd) {}

DamagePlayer DamagePlayer::operator+(const DamagePlayer &other) const {
  DamagePlayer &t = const_cast<DamagePlayer &>(*this);
  DamagePlayer &o = const_cast<DamagePlayer &>(other);
  u32 bd = t.DamageBullet::damage() + o.DamageBullet::damage();
  u32 sd = t.DamageSlow::getSlow() + o.DamageSlow::getSlow();
  u32 wd = t.DamageWave::damage() + o.DamageWave::damage();
  return DamagePlayer(bd, sd, wd);
}

void DamagePlayer::resetSlow() {
  while (slow()) {
  }
}

void DamagePlayer::operator/(const u32 &d) {
  *this = DamagePlayer(DamageBullet::damage() / d, getSlow(),
                       DamageWave::damage() / d);
}

u32 DamagePlayer::damage() {
  u32 d = DamageBullet::damage() + DamageWave::damage();
  *this = DamagePlayer(0, getSlow(), DamageWave::damage());
  return d;
}

void DamagePlayer::accept(VisitorInterface *visitor) const {
  DamagePlayer *t = const_cast<DamagePlayer *>(this);
  if (t->DamageBullet::damage() > 0)
    DamageBullet::accept(visitor);
  if (t->DamageSlow::getSlow() > 0)
    DamageSlow::accept(visitor);
  if (t->DamageWave::damage() > 0)
    DamageWave::accept(visitor);
}

DamagePlayer *DamagePlayer::clone() const { return new DamagePlayer(*this); }

/// DamageEnemy
DamageEnemy::DamageEnemy(u32 damage) : d(damage) {}

DamageEnemy DamageEnemy::operator+(const DamageEnemy &other) const {
  return DamageEnemy(d + other.d);
}

DamageEnemy DamageEnemy::operator+(const u32 &u) const {
  return DamageEnemy(d + u);
}

void DamageEnemy::operator/(const u32 &u) { d /= u; }

u32 DamageEnemy::damage() { return d; }

void DamageEnemy::accept(VisitorInterface *visitor) const {
  visitor->visitDamageEnemy();
}

DamageEnemy *DamageEnemy::clone() const { return new DamageEnemy(*this); }
