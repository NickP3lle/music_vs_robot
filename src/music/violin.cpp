#include "violin.h"

Violin::Violin() : MusicInstruments(50, 100){};

void Violin::levelUpHealthPower() {
    updateHealth(getMaxHealth() + (healthIncrease * getLevel()));
    updatePower(powerIncrease);
}

u32 Violin::getMaxHealth() const { return maxHealth; }