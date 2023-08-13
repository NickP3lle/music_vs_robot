#pragma once
#include "../playground/cash.h"
#include "entity.h"

class PlayerAbstract : public EntityAbstract, public DataManagerInterface {
private:
  u32 h, l;

public:
  PlayerAbstract(u32 health, u32 level);

  u32 &getHealth() override;
  u32 getLevel() const;
  virtual void levelUp();
  virtual u32 getCost() const = 0;
  virtual DamagePlayer *attack() const override = 0;

  std::string toString() const override;
};

class Sample : public PlayerAbstract {
public:
  Sample(u32 level = 1);

  void accept(VisitorInterface *visitor) const override;
  Sample *clone() const override;
  std::string toString() const override;

  virtual DamagePlayer *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
};

class ThreeColumn : public PlayerAbstract {
public:
  ThreeColumn(u32 level = 1);

  void accept(VisitorInterface *visitor) const override;
  ThreeColumn *clone() const override;
  std::string toString() const override;

  virtual DamagePlayer *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
};

class DoubleLife : public PlayerAbstract {
private:
  bool secondLife;

public:
  DoubleLife(u32 = 1, bool = true);

  void accept(VisitorInterface *visitor) const override;
  DoubleLife *clone() const override;
  std::string toString() const override;

  virtual DamagePlayer *attack() const override;

  bool sufferDamage(DamageAbstract *damage) override;
  void levelUp() override;
  u32 getCost() const override;
};

class ThreeRow : public PlayerAbstract {
public:
  ThreeRow(u32 = 1);

  void accept(VisitorInterface *visitor) const override;
  ThreeRow *clone() const override;
  std::string toString() const override;

  virtual DamagePlayer *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
};

class SlowDown : public PlayerAbstract {
public:
  SlowDown(u32 = 1);

  void accept(VisitorInterface *visitor) const override;
  SlowDown *clone() const override;
  std::string toString() const override;

  virtual DamagePlayer *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
};
