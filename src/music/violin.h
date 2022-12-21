#ifndef VIOLIN_H
#define VIOLIN_H

#define VIOLIN_DEFAULT_HEALTH 50
#define VIOLIN_UPDATE_PRICE 100
#define VIOLIN_HEALTH_INCREASE 25
#define VIOLIN_POWER_INCREASE 50

#include "music_instrument.h"
class Violin : public MusicInstruments {
  public:
    Violin();
    bool levelUp() override;
};
#endif
