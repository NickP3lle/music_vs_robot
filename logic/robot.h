#pragma once

#include "entity.h"

class Robot : public Entity {
private:
  u32 a, s, v;

public:
  Robot(u32, u32, bool = false, bool = false);

  bool sufferDamage(Damage *) override;
  DamageRobot *attack() const override final;
  virtual u32 move() const;

  void accept(VisitorGUI *) const override;
  Robot *clone() const override;
};

class RobotDefense : public Robot {
public:
  RobotDefense(u32, u32);
  bool sufferDamage(Damage *) override;
  void accept(VisitorGUI *) const override;
  RobotDefense *clone() const override;
};

class RobotBig : public Robot {
public:
  RobotBig(u32, u32);
  u32 move() const override;
  void accept(VisitorGUI *) const override;
  RobotBig *clone() const override;
};
