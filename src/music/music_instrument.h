#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    u32 level;

  protected:
    virtual void levelUpHealthPower() = 0;

  public:
    MusicInstruments(u32, u32);

    void levelUp();
    // u32 getLevel() const;
};
#endif
