#ifndef MUSIC_IMAGE_VISITOR_H
#define MUSIC_IMAGE_VISITOR_H

#include "entityVisitorInterface.h"

#include <QPixmap>

class MusicImageVisitor : public EntityVisitorInterface {
  private:
    QPixmap *pixmap;

  public:
    void visitViolin() override;
    void visitTrumpet() override;
    void visitDrum() override;
    void visitFlute() override;
    void visitSaxophone() override;

    QPixmap *getPixmap() const;
};

#endif