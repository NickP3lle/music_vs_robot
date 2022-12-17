#include "trumpet.h"

Trumpet::Trumpet() : MusicInstruments(100, 50){};

void Trumpet::levelUpHealthPower() {
    updateHealth(getMaxHealth() + 50);
    updatePower(50);
}

u32 Trumpet::getMaxHealth() const { return maxHealth + (getLevel() - 1) * 50; }