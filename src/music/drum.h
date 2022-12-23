#ifndef DRUM_H
#define DRUM_H

#define DRUM_DEFAULT_HEALTH 200
#define DRUM_UPDATE_PRICE 50
#define DRUM_HEALTH_INCREASE 50
#define DRUM_POWER_INCREASE 100

#include "music_instrument.h"

class Drum : public MusicInstruments {
  public:
    Drum();
    bool levelUp() override;
};
#endif
