#include "musicImageVisitor.h"

void MusicImageVisitor::visitViolin(const Violin &violin) { pixmap = new QPixmap(":/assets/violin.png"); }

void MusicImageVisitor::visitTrumpet(const Trumpet &trumpet) { pixmap = new QPixmap(":/assets/trumpet.png"); }

void MusicImageVisitor::visitDrum(const Drum &drum) { pixmap = new QPixmap(":/assets/drum.png"); }

void MusicImageVisitor::visitFlute(const Flute &flute) { pixmap = new QPixmap(":/assets/flute.png"); }

void MusicImageVisitor::visitSaxophone(const Saxophone &saxophone) { pixmap = new QPixmap(":/assets/saxophone.png"); }

QPixmap *MusicImageVisitor::getPixmap() const { return pixmap; }