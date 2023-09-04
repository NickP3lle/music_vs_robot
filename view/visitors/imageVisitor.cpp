#include "imageVisitor.h"

#include "../../music/music_instrument.h"
#include "../../robot/robot.h"

void imageVisitor::visitViolin() {
  pixmap = new QPixmap(":/assets/violin.png");
}

void imageVisitor::visitTrumpet() {
  pixmap = new QPixmap(":/assets/trumpet.png");
}

void imageVisitor::visitDrum() { pixmap = new QPixmap(":/assets/drum.png"); }

void imageVisitor::visitFlute() { pixmap = new QPixmap(":/assets/flute.png"); }

void imageVisitor::visitSaxophone() {
  pixmap = new QPixmap(":/assets/saxophone.png");
}

void imageVisitor::visitRobot() { pixmap = new QPixmap(":/assets/robot.png"); }

QPixmap *imageVisitor::getPixmap() const { return pixmap; }
