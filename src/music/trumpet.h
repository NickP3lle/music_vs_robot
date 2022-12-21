#ifndef TRUMPET_H
#define TRUMPET_H

#define TRUMPET_DEFAULT_HEALTH 10
#define TRUMPET_UPDATE_PRICE 150
#define TRUMPET_HEALTH_INCREASE 50
#define TRUMPET_POWER_INCREASE 50

#include "music_instrument.h"
class Trumpet : public MusicInstruments {
  public:
    Trumpet();
    bool levelUp() override;
};

#endif
