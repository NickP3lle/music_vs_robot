#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class drum : public MusicInstruments {
  public:
    drum();
    virtual void levelUpHealth();
    virtual void levelUpPower();
};
#endif
