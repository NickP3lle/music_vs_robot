#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class Drum : public MusicInstruments {
  protected:
    virtual void levelUpHealthPower();

  public:
    Drum();
};
#endif
