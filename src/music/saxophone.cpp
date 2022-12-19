#include "saxophone.h"

Saxophone::Saxophone() : MusicInstruments(100, 0){};

void Saxophone::levelUpHealthPower() {
    updateHealth(getMaxHealth() + (healthIncrease * getLevel()));
    updatePower(powerIncrease);
}

u32 Saxophone::getMaxHealth() const { return maxHealth; }