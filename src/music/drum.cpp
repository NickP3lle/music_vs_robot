#include "drum.h"

Drum::Drum() : MusicInstruments(200, 300) {}

void Drum::levelUpHealthPower() {
    updateHealth(getMaxHealth() + 50);
    updatePower(100);
}

u32 Drum::getMaxHealth() const { return maxHealth + (getLevel() - 1) * 50; }