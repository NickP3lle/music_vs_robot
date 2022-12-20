#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    u32 level;

  protected:
    virtual u32 getMaxHealth() const = 0;
    virtual u32 getUpdatePrice() const = 0;

  public:
    MusicInstruments(u32 life, u32 damage);

    virtual bool levelUp();

    u32 getLevel() const;
};
#endif
