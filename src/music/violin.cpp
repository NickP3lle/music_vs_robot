#include "violin.h"

Violin::Violin() : MusicInstruments(50, 100){};

void Violin::levelUpHealthPower() {
    updateHealth(getMaxHealth() + 25);
    updatePower(50);
}

u32 Violin::getMaxHealth() const { return maxHealth + (getLevel() - 1) * 25; }