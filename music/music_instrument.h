#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H
#include "../game/define.h"
#include "../game/entity.h"
#include "../view/visitors/entityVisitorInterface.h"
#include <iostream>
#include <string>

using std::ostream;

/// Classe astratta che rappresenta gli strumenti musicali

class MusicInstruments : public Entity {
  private:
    u32 level;

  public:
    MusicInstruments(u32 life, u32 damage, u32 level = 1);

    // Clone deve avere l'ovveride per vincolare il ritorno di un
    // MusicInstrument alle classi derivate
    virtual MusicInstruments *clone() const override = 0;

    // tre per ogni riga
    // rispettivamente: danni normali, danni da drum, rallentamento
    // i danni normali si infrangono sui robot
    // i danni da drum permangono per tre celle
    // il rallentamento si infrange sui robot e ne dimezza la velocità
    static u32 damages[ROWS][3];

    bool takeDamage(u32 &amount) override;
    virtual void attack(u32 row) const = 0;
    virtual u32 value() const = 0;
    u32 attack() const override final;
    virtual ostream &print(ostream &os) const;
    virtual void levelUp();
    static void resetDamages();

    u32 getLevel() const;
    virtual u32 getCost() const = 0;

    virtual std::string saveData() override;
    virtual MusicInstruments *loadData(std::string) override;
};

/// Classi che rappresentano gli strumenti musicali

/**
 * Flute
 * Attack one column
 */
class Flute : public MusicInstruments {
  public:
    Flute(u32 health = FLUTE_DEFAULT_HEALTH, u32 power = FLUTE_DEFAULT_POWER, u32 level = 1);
    Flute *clone() const override;

    virtual void attack(u32 row) const override;
    void levelUp() override;
    u32 getCost() const override;
    u32 value() const override;
    ostream &print(ostream &os) const override;

    void accept(EntityVisitorInterface &visitor) const override;

    virtual std::string saveData() override;
};

/**
 * Drum
 * Attack three columns
 */
class Drum : public MusicInstruments {
  public:
    Drum(u32 health = DRUM_DEFAULT_HEALTH, u32 power = DRUM_DEFAULT_POWER, u32 level = 1);
    Drum *clone() const override;

    void attack(u32 row) const override;
    void levelUp() override;
    u32 getCost() const override;
    u32 value() const override;
    ostream &print(ostream &os) const override;

    void accept(EntityVisitorInterface &visitor) const override;

    virtual std::string saveData() override;
};

/** Saxophone
 * Double life
 */
class Saxophone : public MusicInstruments {
  private:
    bool secondLife;

  public:
    Saxophone(u32 health = SAXOPHONE_DEFAULT_HEALTH, u32 power = SAXOPHONE_DEFAULT_POWER, u32 level = 1,
              bool secondLife = true);
    Saxophone *clone() const override;

    void attack(u32 row) const override;
    void levelUp() override;
    u32 getCost() const override;
    u32 value() const override;
    bool takeDamage(u32 &) override;
    ostream &print(ostream &os) const override;

    void accept(EntityVisitorInterface &visitor) const override;

    virtual std::string saveData() override;
};

/**
 * Trumpet
 * Attack three rows
 */
class Trumpet : public MusicInstruments {
  public:
    Trumpet(u32 health = TRUMPET_DEFAULT_HEALTH, u32 power = TRUMPET_DEFAULT_POWER, u32 level = 1);
    Trumpet *clone() const override;

    void attack(u32 row) const override;
    void levelUp() override;
    u32 value() const override;
    u32 getCost() const override;
    ostream &print(ostream &os) const override;

    void accept(EntityVisitorInterface &visitor) const override;

    virtual std::string saveData() override;
};

/**
 * Violin
 * Slow down the enemies
 */
class Violin : public MusicInstruments {
  public:
    Violin(u32 health = VIOLIN_DEFAULT_HEALTH, u32 power = VIOLIN_DEFAULT_POWER, u32 level = 1);
    Violin *clone() const override;

    void attack(u32 row) const override;
    void levelUp() override;
    u32 value() const override;
    u32 getCost() const override;
    u32 slowDown() const;
    ostream &print(ostream &os) const override;

    void accept(EntityVisitorInterface &visitor) const override;

    virtual std::string saveData() override;
};

#endif
