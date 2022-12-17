#include "music_instrument.h"

#ifndef SAXOPHONE_H
#define SAXOPHONE_H
class saxophone : public MusicInstruments {
  public:
    saxophone();
    virtual void level_up();
};
#endif
