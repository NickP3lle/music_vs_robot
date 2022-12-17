#include "music_instrument.h"

#ifndef SAXOPHONE_H
#define SAXOPHONE_H
class saxophone : public MusicInstruments {
  public:
    saxophone();
    virtual void levelUpHealth();
    virtual void levelUpPower();
};
#endif
