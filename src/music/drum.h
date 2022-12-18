#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class Drum : public MusicInstruments {
  private:
    static const u32 maxHealth = 200;

  protected:
    void levelUpHealthPower() override;

  public:
    Drum();

    u32 getMaxHealth() const override;
};
#endif
