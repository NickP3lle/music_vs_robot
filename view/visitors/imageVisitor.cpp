#include "ImageVisitor.h"

void ImageVisitor::visitSlowDown() const { pixmap = new QPixmap(":/assets/violin.png"); }

void ImageVisitor::visitThreeRow() const { pixmap = new QPixmap(":/assets/trumpet.png"); }

void ImageVisitor::visitThreeColumn() const { pixmap = new QPixmap(":/assets/drum.png"); }

void ImageVisitor::visitSample() const { pixmap = new QPixmap(":/assets/flute.png"); }

void ImageVisitor::visitDoubleLife() const { pixmap = new QPixmap(":/assets/saxophone.png"); }

void ImageVisitor::visitEnemy() const { pixmap = new QPixmap(":/assets/robot.png"); }

QPixmap *ImageVisitor::getPixmap() const { return pixmap; }
