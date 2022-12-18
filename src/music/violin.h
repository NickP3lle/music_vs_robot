#include "music_instrument.h"

#ifndef VIOLIN_H
#define VIOLIN_H
class Violin : public MusicInstruments {
  private:
    static const u32 maxHealth = 50;

  protected:
    void levelUpHealthPower() override;

  public:
    Violin();

    u32 getMaxHealth() const override;
};
#endif
