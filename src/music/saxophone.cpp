#include "saxophone.h"

Saxophone::Saxophone() : MusicInstruments(100, 0){};

bool Saxophone::levelUp() {
    if (!(MusicInstruments::levelUp())) {
        // soldi insufficienti o livello massimo già raggiunto
        return false;
    }

    // level è già stato incrementato
    updateHealth(getMaxHealth() + (healthIncrease * (getLevel() - 1)));
    updatePower(powerIncrease);
    return true;
}

u32 Saxophone::getMaxHealth() const { return maxHealth; }

u32 Saxophone::getUpdatePrice() const { return updatePrice; }