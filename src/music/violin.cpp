#include "violin.h"

Violin::Violin() : MusicInstruments(50, 100){};

bool Violin::levelUp() {
    if (!(MusicInstruments::levelUp())) {
        // soldi insufficienti o livello massimo già raggiunto
        return false;
    }

    // level è già stato incrementato
    updateHealth(getMaxHealth() + (healthIncrease * (getLevel() - 1)));
    updatePower(powerIncrease);
    return true;
}

u32 Violin::getMaxHealth() const { return maxHealth; }

u32 Violin::getUpdatePrice() const { return updatePrice; }