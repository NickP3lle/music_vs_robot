#pragma once

#include "../../util/visitor.h"

#include <QPixmap>

class ImageVisitor : public VisitorInterface {
  private:
    QPixmap *pixmap;

  public:
    /// Damage
    void visitDamageBullet() override;
    void visitDamageSlow() override;
    void visitDamageWave() override;

    /// Player
    void visitSample() override;
    void visitThreeColumn() override;
    void visitDoubleLife() override;
    void visitThreeRow() override;
    void visitSlowDown() override;

    /// Robot
    void visitEnemy() override;
    void visitEnemyDefense() override;
    void visitEnemyBig() override;

    /// Tool
    void visitToolWeapon() override;
    void visitToolArmor() override;
    void visitToolBoots() override;
    void visitToolRing() override;

    QPixmap *getPixmap() const;
};
