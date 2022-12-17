#include "music_instrument.h"

#ifndef FLUTE_H
#define FLUTE_H
class flute : public MusicInstruments {
  public:
    flute();
    virtual void levelUpHealth();
    virtual void levelUpPower();
};
#endif
