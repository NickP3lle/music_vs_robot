#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    u32 level;

  protected:
    bool checkLevelUp(u32);

  public:
    MusicInstruments(u32 life, u32 damage);

    virtual bool levelUp() = 0;

    u32 attack() const override final;

    u32 getLevel() const;
};
#endif
