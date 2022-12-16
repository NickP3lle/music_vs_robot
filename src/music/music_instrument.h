#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    int level;

  public:
    MusicInstruments(u32, u32);
    virtual u32 levelUp() = 0;
};
#endif
