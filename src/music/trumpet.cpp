#include "trumpet.h"

Trumpet::Trumpet() : MusicInstruments(100, 50){};

bool Trumpet::levelUp() {
    if (!(MusicInstruments::levelUp())) {
        // soldi insufficienti o livello massimo già raggiunto
        return false;
    }

    // level è già stato incrementato
    updateHealth(getMaxHealth() + (healthIncrease * (getLevel() - 1)));
    updatePower(powerIncrease);
    return true;
}

u32 Trumpet::getMaxHealth() const { return maxHealth; }

u32 Trumpet::getUpdatePrice() const { return updatePrice; }