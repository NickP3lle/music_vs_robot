#include "ImageVisitor.h"

void ImageVisitor::visitDamageBullet() const {
  pixmap = new QPixmap(":/assets/DamageBullet.png");
}

void ImageVisitor::visitDamageSlow() const {
  pixmap = new QPixmap(":/assets/DamageSlow.png");
}

void ImageVisitor::visitDamageWave() const {
  pixmap = new QPixmap(":/assets/DamageWave.png");
}

void ImageVisitor::visitSlowDown() const {
  pixmap = new QPixmap(":/assets/Violin.png");
}

void ImageVisitor::visitThreeRow() const {
  pixmap = new QPixmap(":/assets/Trumpet.png");
}

void ImageVisitor::visitThreeColumn() const {
  pixmap = new QPixmap(":/assets/Drum.png");
}

void ImageVisitor::visitSample() const {
  pixmap = new QPixmap(":/assets/Flute.png");
}

void ImageVisitor::visitDoubleLife() const {
  pixmap = new QPixmap(":/assets/Saxophone.png");
}

void ImageVisitor::visitEnemy() const {
  pixmap = new QPixmap(":/assets/Robot.png");
}

void ImageVisitor::visitEnemyDefense() const {
  pixmap = new QPixmap(":/assets/RobotDefense.png");
}

void ImageVisitor::visitEnemyBig() const {
  pixmap = new QPixmap(":/assets/RobotBig.png");
}

void ImageVisitor::visitToolWeapon() const {
  pixmap = new QPixmap(":/assets/ToolWeapon.png");
}

void ImageVisitor::visitToolArmor() const {
  pixmap = new QPixmap(":/assets/ToolArmor.png");
}

void ImageVisitor::visitToolBoots() const {
  pixmap = new QPixmap(":/assets/ToolBoots.png");
}

void ImageVisitor::visitToolRing() const {
  pixmap = new QPixmap(":/assets/ToolRing.png");
}

QPixmap *ImageVisitor::getPixmap() const { return pixmap; }
