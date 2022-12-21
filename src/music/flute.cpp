#include "flute.h"

Flute::Flute() : MusicInstruments(FLUTE_DEFAULT_HEALTH, 100){};

bool Flute::levelUp() {
    if (!(checkLevelUp(FLUTE_UPDATE_PRICE))) {
        return false;
    }

    // level è già stato incrementato
    updateHealth(FLUTE_DEFAULT_HEALTH + (FLUTE_HEALTH_INCREASE * (getLevel() - 1)));
    updatePower(FLUTE_POWER_INCREASE);
    return true;
}