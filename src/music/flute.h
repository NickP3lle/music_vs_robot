#ifndef FLUTE_H
#define FLUTE_H

#define FLUTE_DEFAULT_HEALTH 100
#define FLUTE_UPDATE_PRICE 75
#define FLUTE_HEALTH_INCREASE 50
#define FLUTE_POWER_INCREASE 50

#include "music_instrument.h"
class Flute : public MusicInstruments {
  public:
    Flute();
    bool levelUp() override;
};
#endif
