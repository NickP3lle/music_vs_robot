#include "flute.h"

Flute::Flute() : MusicInstruments(100, 100){};

void Flute::levelUpHealthPower() {
    updateHealth(getMaxHealth() + 50);
    updatePower(50);
}

u32 Flute::getMaxHealth() const { return maxHealth + (getLevel() - 1) * 50; }