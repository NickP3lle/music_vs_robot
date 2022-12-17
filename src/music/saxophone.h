#include "music_instrument.h"

#ifndef SAXOPHONE_H
#define SAXOPHONE_H
class Saxophone : public MusicInstruments {
  protected:
    virtual void levelUpHealthPower();

  public:
    Saxophone();
};
#endif
