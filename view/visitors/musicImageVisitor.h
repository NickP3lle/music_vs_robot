#ifndef MUSIC_IMAGE_VISITOR_H
#define MUSIC_IMAGE_VISITOR_H

#include "entityVisitorInterface.h"

#include <QPixmap>

class MusicImageVisitor : public EntityVisitorInterface {
  private:
    QPixmap *pixmap;

  public:
    void visitViolin(const Violin &violin) override;
    void visitTrumpet(const Trumpet &trumpet) override;
    void visitDrum(const Drum &drum) override;
    void visitFlute(const Flute &flute) override;
    void visitSaxophone(const Saxophone &saxophone) override;

    QPixmap *getPixmap() const;
};

#endif