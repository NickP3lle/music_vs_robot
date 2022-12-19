#include "drum.h"

Drum::Drum() : MusicInstruments(200, 300) {}

void Drum::levelUpHealthPower() {
    updateHealth(getMaxHealth() + (healthIncrease * getLevel()));
    updatePower(powerIncrease);
}

u32 Drum::getMaxHealth() const { return maxHealth; }