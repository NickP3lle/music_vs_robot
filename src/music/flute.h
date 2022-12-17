#include "music_instrument.h"

#ifndef FLUTE_H
#define FLUTE_H
class Flute : public MusicInstruments {
  protected:
    virtual void levelUpHealthPower();

  public:
    Flute();
};
#endif
