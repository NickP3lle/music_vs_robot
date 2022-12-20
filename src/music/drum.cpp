#include "drum.h"

Drum::Drum() : MusicInstruments(200, 300) {}

bool Drum::levelUp() {
    if (!(MusicInstruments::levelUp())) {
        // soldi insufficienti o livello massimo già raggiunto
        return false;
    }

    // level è già stato incrementato
    updateHealth(getMaxHealth() + (healthIncrease * (getLevel() - 1)));
    updatePower(powerIncrease);
    return true;
}

u32 Drum::getMaxHealth() const { return maxHealth; }

u32 Drum::getUpdatePrice() const { return updatePrice; }