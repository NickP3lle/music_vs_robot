#include "musicImageVisitor.h"

#include "../../music/music_instrument.h"

void MusicImageVisitor::visitViolin() { pixmap = new QPixmap(":/assets/violin.png"); }

void MusicImageVisitor::visitTrumpet() { pixmap = new QPixmap(":/assets/trumpet.png"); }

void MusicImageVisitor::visitDrum() { pixmap = new QPixmap(":/assets/drum.png"); }

void MusicImageVisitor::visitFlute() { pixmap = new QPixmap(":/assets/flute.png"); }

void MusicImageVisitor::visitSaxophone() { pixmap = new QPixmap(":/assets/saxophone.png"); }

QPixmap *MusicImageVisitor::getPixmap() const { return pixmap; }