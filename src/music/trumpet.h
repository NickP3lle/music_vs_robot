#include "music_instrument.h"

#ifndef TRUMPET_H
#define TRUMPET_H
class Trumpet : public MusicInstruments {
  protected:
    virtual void levelUpHealthPower();

  public:
    Trumpet();
};

#endif
