#pragma once

#include "../../logic/util/visitor.h"

#include <QPixmap>

class ImageVisitor : public VisitorInterface {
  private:
    QPixmap *pixmap;

  public:
    /// Damage
    void visitDamageBullet() const override{};
    void visitDamageSlow() const override{};
    void visitDamageWave() const override{};
    void visitDamageEnemy() const override{};

    /// Player
    void visitSample() const override;
    void visitThreeColumn() const override;
    void visitDoubleLife() const override;
    void visitThreeRow() const override;
    void visitSlowDown() const override;

    /// Robot
    void visitEnemy() const override;
    void visitEnemyDefense() const override;
    void visitEnemyBig() const override;

    /// Tool
    void visitToolWeapon() const override{};
    void visitToolArmor() const override{};
    void visitToolBoots() const override{};
    void visitToolRing() const override{};

    QPixmap *getPixmap() const;
};