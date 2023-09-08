#pragma once
#include "../include.h"

class DamageAbstract : public CloneableInterface {
public:
  virtual u32 damage() = 0;
  virtual void operator/(const u32 &d) = 0;
  // virtual void accept(VisitorInterface *visitor) const = 0;
};

class DamageBullet : public VisitableInterface {
private:
  u32 d;

public:
  DamageBullet(u32 damage);
  u32 &damage();
  void accept(VisitorInterface *visitor) const override;
};

class DamageSlow : public VisitableInterface {
private:
  u32 s;

public:
  DamageSlow(u32 slow);
  u32 getSlow();
  bool slow();
  void accept(VisitorInterface *visitor) const override;
};

class DamageWave : public VisitableInterface {
private:
  u32 d;
  int p;

public:
  DamageWave(u32 damage, int period = 4);
  void oneWave();
  u32 &damage();
  void accept(VisitorInterface *visitor) const override;
};

class DamagePlayer : public DamageAbstract,
                     public DamageBullet,
                     public DamageSlow,
                     public DamageWave {
public:
  DamagePlayer(u32 bd, u32 sd, u32 wd);
  DamagePlayer operator+(const DamagePlayer &d) const;
  void resetSlow();
  void operator/(const u32 &d) override;
  u32 damage() override;
  void accept(VisitorInterface *visitor) const override;
  DamagePlayer *clone() const override;
};

class DamageEnemy : public DamageAbstract {
private:
  u32 d;

public:
  DamageEnemy(u32 damage);
  DamageEnemy operator+(const DamageEnemy &d) const;
  DamageEnemy operator+(const u32 &d) const;
  void operator/(const u32 &d) override;
  u32 damage() override;
  DamageEnemy *clone() const override;
};
