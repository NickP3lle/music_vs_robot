#ifndef SAXOPHONE_H
#define SAXOPHONE_H

#define SAXOPHONE_DEFAULT_HEALTH 100
#define SAXOPHONE_UPDATE_PRICE 50
#define SAXOPHONE_HEALTH_INCREASE 100
#define SAXOPHONE_POWER_INCREASE 0

#include "music_instrument.h"
class Saxophone : public MusicInstruments {
  public:
    Saxophone();
    bool levelUp() override;
};
#endif
