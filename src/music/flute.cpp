#include "flute.h"

Flute::Flute() : MusicInstruments(100, 100){};

bool Flute::levelUp() {
    if (!(MusicInstruments::levelUp())) {
        // soldi insufficienti o livello massimo già raggiunto
        return false;
    }

    // level è già stato incrementato
    updateHealth(getMaxHealth() + (healthIncrease * (getLevel() - 1)));
    updatePower(powerIncrease);
    return true;
}

u32 Flute::getMaxHealth() const { return maxHealth; }

u32 Flute::getUpdatePrice() const { return updatePrice; }