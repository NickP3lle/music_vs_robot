#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class drum : public MusicInstruments {
  public:
    drum();
    virtual void level_up();
};
#endif
