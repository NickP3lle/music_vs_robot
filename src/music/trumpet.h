#include "music_instrument.h"

#ifndef TRUMPET_H
#define TRUMPET_H
class Trumpet : public MusicInstruments {
  private:
    static const u32 maxHealth = 100;

  protected:
    void levelUpHealthPower() override;

  public:
    Trumpet();

    u32 getMaxHealth() const override;
};

#endif
