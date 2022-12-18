#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
  private:
    u32 level;

  protected:
    virtual void levelUpHealthPower() = 0;

  public:
    MusicInstruments(u32 life, u32 damage);

    virtual u32 getMaxHealth() const = 0;

    void levelUp();
    u32 getLevel() const;
};
#endif
