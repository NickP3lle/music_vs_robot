#ifndef IMAGE_VISITOR_H
#define IMAGE_VISITOR_H

#include "entityVisitorInterface.h"

#include <QPixmap>

class imageVisitor : public EntityVisitorInterface {
  private:
    QPixmap *pixmap;

  public:
    void visitViolin() override;
    void visitTrumpet() override;
    void visitDrum() override;
    void visitFlute() override;
    void visitSaxophone() override;

    void visitRobot() override;

    QPixmap *getPixmap() const;
};

#endif