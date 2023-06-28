#ifndef ENTITY_VISITOR_INTERFACE_H
#define ENTITY_VISITOR_INTERFACE_H

class Violin;
class Trumpet;
class Drum;
class Flute;
class Saxophone;

class EntityVisitorInterface {
  public:
    virtual void visitViolin(const Violin &violin) = 0;
    virtual void visitTrumpet(const Trumpet &trumpet) = 0;
    virtual void visitDrum(const Drum &drum) = 0;
    virtual void visitFlute(const Flute &flute) = 0;
    virtual void visitSaxophone(const Saxophone &saxophone) = 0;

    // virtual void visitRobot(Robot *robot) = 0;

    virtual ~EntityVisitorInterface() = default;
};

#endif