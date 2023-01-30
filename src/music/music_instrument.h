#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H
#include "../define.h"
#include "../entity.h"
#include <iostream>
#include <string>

using std::ostream;

class MusicInstruments : public Entity {
private:
  u32 level;

public:
  static u32 damages[ROWS][3];
  MusicInstruments(u32 life, u32 damage, u32 level = 0);
  virtual MusicInstruments *clone() const override = 0;
  bool takeDamage(u32 &damage) override;
  u32 attack() const override final;
  virtual void attack(u32 row) const = 0;
  virtual u32 getCost() const = 0;
  virtual u32 value() const = 0;
  virtual ostream &print(ostream &os) const;
  virtual void levelUp();
  u32 getLevel() const;
  static void resetDamages();
};

class Flute : public MusicInstruments {
public:
  Flute(u32 health = FLUTE_DEFAULT_HEALTH, u32 power = FLUTE_DEFAULT_POWER,
        u32 level = 0);
  Flute *clone() const override;
  virtual void attack(u32 row) const override;
  void levelUp() override;
  u32 getCost() const override { return FLUTE_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  ostream &print(ostream &os) const override;
};

class Drum : public MusicInstruments {
public:
  Drum(u32 health = DRUM_DEFAULT_HEALTH, u32 power = DRUM_DEFAULT_POWER,
       u32 level = 0);
  Drum *clone() const override;
  void attack(u32 row) const override;
  void levelUp() override;
  u32 getCost() const override { return DRUM_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  ostream &print(ostream &os) const override;
};

class Saxophone : public MusicInstruments {
private:
  bool secondLife;

public:
  Saxophone(u32 health = SAXOPHONE_DEFAULT_HEALTH,
            u32 power = SAXOPHONE_DEFAULT_POWER, u32 level = 0,
            bool secondLife = true);
  Saxophone *clone() const override;
  void attack(u32 row) const override;
  void levelUp() override;
  u32 getCost() const override { return SAXOPHONE_UPDATE_PRICE * 0.75; }
  u32 value() const override;
  bool takeDamage(u32 &) override;
  ostream &print(ostream &os) const override;
};

class Trumpet : public MusicInstruments {
public:
  Trumpet(u32 health = TRUMPET_DEFAULT_HEALTH,
          u32 power = TRUMPET_DEFAULT_POWER, u32 level = 0);
  Trumpet *clone() const override;
  void attack(u32 row) const override;
  void levelUp() override;
  u32 value() const override;
  u32 getCost() const override { return TRUMPET_UPDATE_PRICE * 0.75; }
  ostream &print(ostream &os) const override;
};

class Violin : public MusicInstruments {
public:
  Violin(u32 health = VIOLIN_DEFAULT_HEALTH, u32 power = VIOLIN_DEFAULT_POWER,
         u32 level = 0);
  Violin *clone() const override;
  void attack(u32 row) const override;
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
  music(const std::string &);
  bool operator==(const music &other) const;
  static MusicInstruments *readMusic(std::istream &is);
  static MusicInstruments *New(music type);
};

#endif
