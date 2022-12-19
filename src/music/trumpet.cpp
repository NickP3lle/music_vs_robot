#include "trumpet.h"

Trumpet::Trumpet() : MusicInstruments(100, 50){};

void Trumpet::levelUpHealthPower() {
    updateHealth(getMaxHealth() + (healthIncrease * getLevel()));
    updatePower(powerIncrease);
}

u32 Trumpet::getMaxHealth() const { return maxHealth; }