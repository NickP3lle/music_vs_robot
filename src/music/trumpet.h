#include "music_instrument.h"

#ifndef TRUMPET_H
#define TRUMPET_H
class trumpet : public MusicInstruments {
  public:
    trumpet();
    virtual void level_up();
};

#endif
