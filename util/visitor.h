#pragma once

class VisitorInterface {
  public:
    /// Damage
    virtual void visitDamageBullet() = 0;
    virtual void visitDamageSlow() = 0;
    virtual void visitDamageWave() = 0;

    /// Player
    virtual void visitSample() = 0;
    virtual void visitThreeColumn() = 0;
    virtual void visitDoubleLife() = 0;
    virtual void visitThreeRow() = 0;
    virtual void visitSlowDown() = 0;

    /// Robot
    virtual void visitEnemy() = 0;
    virtual void visitEnemyDefense() = 0;
    virtual void visitEnemyBig() = 0;

    /// Tool
    virtual void visitToolWeapon() = 0;
    virtual void visitToolArmor() = 0;
    virtual void visitToolBoots() = 0;
    virtual void visitToolRing() = 0;

    virtual ~VisitorInterface() = default;
};

class VisitableInterface {
  public:
    virtual void accept(VisitorInterface *visitor) const = 0;

    virtual ~VisitableInterface() = default;
};
