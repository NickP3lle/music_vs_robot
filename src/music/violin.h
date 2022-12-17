#include "music_instrument.h"

#ifndef VIOLIN_H
#define VIOLIN_H
class Violin : public MusicInstruments {
  protected:
    virtual void levelUpHealthPower();

  public:
    Violin();
};
#endif
