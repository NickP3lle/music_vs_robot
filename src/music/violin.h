#include "music_instrument.h"

#ifndef VIOLIN_H
#define VIOLIN_H
class violin : public MusicInstruments {
  public:
    violin();
    virtual void levelUpHealth();
    virtual void levelUpPower();
};
#endif
