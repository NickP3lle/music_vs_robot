#pragma once

class VisitorInterface {
public:
  /// Damage
  virtual void visitDamageBullet() const = 0;
  virtual void visitDamageSlow() const = 0;
  virtual void visitDamageWave() const = 0;
  virtual void visitDamageEnemy() const = 0;

  /// Player
  virtual void visitSample() const = 0;
  virtual void visitThreeColumn() const = 0;
  virtual void visitDoubleLife() const = 0;
  virtual void visitThreeRow() const = 0;
  virtual void visitSlowDown() const = 0;

  /// Robot
  virtual void visitEnemy() const = 0;
  virtual void visitEnemyDefense() const = 0;
  virtual void visitEnemyBig() const = 0;

  /// Tool
  virtual void visitToolWeapon() const = 0;
  virtual void visitToolArmor() const = 0;
  virtual void visitToolBoots() const = 0;
  virtual void visitToolRing() const = 0;

  virtual ~VisitorInterface() = default;
};

class VisitableInterface {
public:
  virtual void accept(VisitorInterface *visitor) const = 0;

  virtual ~VisitableInterface() = default;
};
