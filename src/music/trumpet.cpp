#include "trumpet.h"

Trumpet::Trumpet() : MusicInstruments(TRUMPET_DEFAULT_HEALTH, 50){};

bool Trumpet::levelUp() {
    if (!(checkLevelUp(TRUMPET_UPDATE_PRICE))) {
        return false;
    }

    // level è già stato incrementato
    updateHealth(TRUMPET_DEFAULT_HEALTH + (TRUMPET_HEALTH_INCREASE * (getLevel() - 1)));
    updatePower(TRUMPET_POWER_INCREASE);
    return true;
}