#include "imageVisitor.h"

void ImageVisitor::visitDamageBullet() { pixmap = new QPixmap(":/assets/DamageBullet.png"); }

void ImageVisitor::visitDamageSlow() { pixmap = new QPixmap(":/assets/DamageSlow.png"); }

void ImageVisitor::visitDamageWave() { pixmap = new QPixmap(":/assets/DamageWave.png"); }

void ImageVisitor::visitSlowDown() { pixmap = new QPixmap(":/assets/Violin.png"); }

void ImageVisitor::visitThreeRow() { pixmap = new QPixmap(":/assets/Trumpet.png"); }

void ImageVisitor::visitThreeColumn() { pixmap = new QPixmap(":/assets/Drum.png"); }

void ImageVisitor::visitSample() { pixmap = new QPixmap(":/assets/Flute.png"); }

void ImageVisitor::visitDoubleLife() { pixmap = new QPixmap(":/assets/Saxophone.png"); }

void ImageVisitor::visitEnemy() { pixmap = new QPixmap(":/assets/Robot.png"); }

void ImageVisitor::visitEnemyDefense() { pixmap = new QPixmap(":/assets/RobotDefense.png"); }

void ImageVisitor::visitEnemyBig() { pixmap = new QPixmap(":/assets/RobotBig.png"); }

void ImageVisitor::visitToolWeapon() {
    toolPixmap = new QPixmap(":/assets/ToolWeapon.png");
    painter = new QPainter(pixmap);
    painter->drawPixmap(0, 0, *toolPixmap);
}

void ImageVisitor::visitToolArmor() {
    toolPixmap = new QPixmap(":/assets/ToolArmor.png");
    painter = new QPainter(pixmap);
    painter->drawPixmap(0, 0, *toolPixmap);
}

void ImageVisitor::visitToolBoots() {
    toolPixmap = new QPixmap(":/assets/ToolBoots.png");
    painter = new QPainter(pixmap);
    painter->drawPixmap(0, 0, *toolPixmap);
}

void ImageVisitor::visitToolRing() {
    toolPixmap = new QPixmap(":/assets/ToolRing.png");
    painter = new QPainter(pixmap);
    painter->drawPixmap(0, 0, *toolPixmap);
}

QPixmap *ImageVisitor::getPixmap() const { return pixmap; }
