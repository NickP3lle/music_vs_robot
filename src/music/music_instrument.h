#include "../entity.h"
#include <iostream>
using std::ostream;

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H

class MusicInstruments : public Entity {
private:
  u32 level;

public:
  u32 health;
  u32 power;
  MusicInstruments(u32 life, u32 damage);
  virtual MusicInstruments *clone() const override = 0;
  bool takeDamage(u32 &damage) override;
  u32 attack() const override final;
  virtual u32 getCost() const = 0;
  virtual u32 value() const = 0;
  virtual ostream &print(ostream &out) const = 0;
  virtual void levelUp();
  u32 getLevel() const;
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
  void levelUp() override;
  u32 getCost() const override { return FLUTE_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  ostream &print(ostream &os) const override;
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
  void levelUp() override;
  u32 getCost() const override { return DRUM_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  ostream &print(ostream &os) const override;
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
  Saxophone *clone() const override;
  void levelUp() override;
  u32 getCost() const override { return SAXOPHONE_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  bool takeDamage(u32 &) override;
  ostream &print(ostream &os) const override;
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
  void levelUp() override;
  u32 value() const override;
  u32 getCost() const override { return TRUMPET_UPDATE_PRICE * 0.75; }
  ostream &print(ostream &os) const override;
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
  void levelUp() override;
  u32 value() const override;
  u32 getCost() const override { return VIOLIN_UPDATE_PRICE * 0.75; }
  u32 slowDown() const;
  ostream &print(ostream &os) const override;
};

// 0 -> flute
// 1 -> Drum
// 2 -> Saxophone
// 3 -> Trumpet
// >3 -> Violin

#define NORMIE music_enum::normie
#define THREE_C music_enum::three_c
#define DOUBLE_L music_enum::double_l
#define THREE_R music_enum::three_r
#define SLOW music_enum::slow

enum music_enum {
  normie = 0,   // flute
  three_c = 1,  // three columns -> drum
  double_l = 2, // double life -> saxophone
  three_r = 3,  // three rows -> trumpet
  slow = 4      // slow -> violin
};

class music {
public:
  music_enum type;
  music(music_enum type);
  music(u32 type);
  music(const MusicInstruments *const);
  music(const MusicInstruments &);
  operator unsigned int() const;
  static MusicInstruments *New(music type);
};

#endif
