#include "cash.h"
#include "entity.h"
#include "include.h"

class PlayerAbstract : public EntityAbstract, public DataManager {
private:
  u32 h, l;

public:
  PlayerAbstract(u32 health, u32 level);

  bool sufferDamage(DamageAbstract *damage) override;

  u32 &getHealth() const override;
  u32 getLevel() const;
  virtual void levelUp();
  virtual u32 getCost() const = 0;
  virtual u32 value() const = 0;

  std::string toString() const override;
};

class Sample : public PlayerAbstract {
public:
  Sample(u32 health, u32 level);

  void accept(VisitorGUI *visitor) const override;
  Sample *clone() const override;
  std::string toString() const override;

  virtual DamageBullet *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
  u32 value() const override;
};

class ThreeColumn : public PlayerAbstract {
public:
  ThreeColumn(u32 health, u32 level);

  void accept(VisitorGUI *visitor) const override;
  ThreeColumn *clone() const override;
  std::string toString() const override;

  virtual DamageWave *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
  u32 value() const override;
};

class DoubleLife : public PlayerAbstract {
private:
  bool secondLife;

public:
  DoubleLife(u32 health, u32 level, bool doubleLife);

  void accept(VisitorGUI *visitor) const override;
  DoubleLife *clone() const override;
  std::string toString() const override;

  virtual DamageBullet *attack() const override;

  bool sufferDamage(DamageAbstract *damage) override;
  void levelUp() override;
  u32 getCost() const override;
  u32 value() const override;
};

class ThreeRow : public PlayerAbstract {
public:
  ThreeRow(u32 health, u32 level);

  void accept(VisitorGUI *visitor) const override;
  ThreeRow *clone() const override;
  std::string toString() const override;

  virtual DamageBullet *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
  u32 value() const override;
};

class SlowDown : public PlayerAbstract {
public:
  SlowDown(u32 health, u32 level);

  void accept(VisitorGUI *visitor) const override;
  SlowDown *clone() const override;
  std::string toString() const override;

  virtual DamageSlow *attack() const override;

  void levelUp() override;
  u32 getCost() const override;
  u32 value() const override;
};
