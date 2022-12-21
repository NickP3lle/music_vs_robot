#include "saxophone.h"

Saxophone::Saxophone() : MusicInstruments(SAXOPHONE_DEFAULT_HEALTH, 0){};

bool Saxophone::levelUp() {
    if (!(checkLevelUp(SAXOPHONE_UPDATE_PRICE))) {
        return false;
    }

    // level è già stato incrementato
    updateHealth(SAXOPHONE_DEFAULT_HEALTH + (SAXOPHONE_HEALTH_INCREASE * (getLevel() - 1)));
    updatePower(SAXOPHONE_POWER_INCREASE);
    return true;
}