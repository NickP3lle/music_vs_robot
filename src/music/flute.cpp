#include "flute.h"

Flute::Flute() : MusicInstruments(100, 100){};

void Flute::levelUpHealthPower() {
    updateHealth(getMaxHealth() + (healthIncrease * getLevel()));
    updatePower(powerIncrease);
}

u32 Flute::getMaxHealth() const { return maxHealth; }