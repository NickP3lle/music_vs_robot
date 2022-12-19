#include "music_instrument.h"

#ifndef FLUTE_H
#define FLUTE_H
class Flute : public MusicInstruments {
  private:
    static const u32 maxHealth = 100;
    static const u32 healthIncrease = 50;
    static const u32 powerIncrease = 50;

  protected:
    void levelUpHealthPower() override;
    u32 getMaxHealth() const override;

  public:
    Flute();
};
#endif
