#include "saxophone.h"

Saxophone::Saxophone() : MusicInstruments(100, 0){};

void Saxophone::levelUpHealthPower() {
    updateHealth(getMaxHealth() + 100);
    updatePower();
}

u32 Saxophone::getMaxHealth() const { return maxHealth + (getLevel() - 1) * 100; }