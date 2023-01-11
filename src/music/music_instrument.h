#include "../entity.h"
#include <iostream>
using std::ostream;

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
private:
  u32 level;

public:
  bool checkLevelUp(u32); // da pensare se toglierla
  MusicInstruments(u32 life, u32 damage);
  virtual bool levelUp() = 0;
  virtual u32 attack() const override final;
  u32 getLevel() const;
};

#define DRUM_DEFAULT_HEALTH 200
#define DRUM_UPDATE_PRICE 50
#define DRUM_HEALTH_INCREASE 50
#define DRUM_POWER_INCREASE 100

#include "music_instrument.h"

class Drum : public MusicInstruments {
public:
  Drum();
  Drum *clone() const override;
  bool levelUp() override;
};

#define FLUTE_DEFAULT_HEALTH 100
#define FLUTE_UPDATE_PRICE 75
#define FLUTE_HEALTH_INCREASE 50
#define FLUTE_POWER_INCREASE 50

#include "music_instrument.h"
class Flute : public MusicInstruments {
public:
  Flute();
  Flute *clone() const override;
  bool levelUp() override;
};

#define SAXOPHONE_DEFAULT_HEALTH 100
#define SAXOPHONE_UPDATE_PRICE 50
#define SAXOPHONE_HEALTH_INCREASE 100
#define SAXOPHONE_POWER_INCREASE 0

#include "music_instrument.h"
class Saxophone : public MusicInstruments {
private:
  bool secondLife;

public:
  Saxophone();
  bool takeDamage(u32 &) override;
  Saxophone *clone() const override;
  bool levelUp() override;
};

#define TRUMPET_DEFAULT_HEALTH 10
#define TRUMPET_UPDATE_PRICE 150
#define TRUMPET_HEALTH_INCREASE 50
#define TRUMPET_POWER_INCREASE 50

#include "music_instrument.h"
class Trumpet : public MusicInstruments {
public:
  Trumpet();
  Trumpet *clone() const override;
  bool levelUp() override;
};

#define VIOLIN_DEFAULT_HEALTH 50
#define VIOLIN_UPDATE_PRICE 100
#define VIOLIN_HEALTH_INCREASE 25
#define VIOLIN_POWER_INCREASE 50

#include "music_instrument.h"
class Violin : public MusicInstruments {
public:
  Violin();
  Violin *clone() const override;
  bool levelUp() override;
};

// 0 -> flute
// 1 -> Drum
// 2 -> Saxophone
// 3 -> Trumpet
// >3 -> Violin
namespace music {
MusicInstruments *New(u32 type);
} // namespace music
#endif
