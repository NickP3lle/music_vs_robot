#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    int level;

  public:
    MusicInstruments(u32, u32);
    virtual void levelUp() = 0;

    void addLevel();
    u32 getLevel() const;
};
#endif
