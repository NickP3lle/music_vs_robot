#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class Drum : public MusicInstruments {
  private:
    static const u32 maxHealth = 200;
    static const u32 updatePrice = 50;
    static const u32 healthIncrease = 50;
    static const u32 powerIncrease = 100;

  protected:
    u32 getMaxHealth() const override;
    u32 getUpdatePrice() const override;

  public:
    Drum();
    bool levelUp() override;
};
#endif
