#pragma once
#include "include.h"

class Damage : public AcceptGUI, public Cloneable {
  u32 d;

public:
  Damage(u32 damage);
  virtual u32 getDamage() const;
};

class DamageBullet : public Damage {
private:
public:
  DamageBullet(u32 damage);
  void accept(VisitorGUI *visitor) const override;
  DamageBullet *clone() const override;
};

class DamageSlow : public Damage {
private:
  u32 slow;

public:
  DamageSlow(u32 damage, u32 slow);
  bool getSlow();
  void accept(VisitorGUI *visitor) const override;
  DamageSlow *clone() const override;
};

class DamageWave : public Damage {
private:
  u32 persistance;

public:
  DamageWave(u32 wave);
  bool oneWave();
  void accept(VisitorGUI *visitor) const override;
  DamageWave *clone() const override;
};

class DamageRobot : public Damage {
private:
public:
  DamageRobot(u32 damage);
  void accept(VisitorGUI *visitor) const override;
  DamageRobot *clone() const override;
};
