#include "music_instrument.h"

#ifndef FLUTE_H
#define FLUTE_H
class Flute : public MusicInstruments {
  private:
    static const u32 maxHealth = 100;

  protected:
    void levelUpHealthPower() override;

  public:
    Flute();

    u32 getMaxHealth() const override;
};
#endif
