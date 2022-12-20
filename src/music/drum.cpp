#include "drum.h"

Drum::Drum() : MusicInstruments(DRUM_DEFAULT_HEALTH, 300) {}

bool Drum::levelUp() {
    if (!(checkLevelUp(DRUM_UPDATE_PRICE))) {
        return false;
    }

    // level è già stato incrementato
    updateHealth(DRUM_DEFAULT_HEALTH + (DRUM_HEALTH_INCREASE * (getLevel() - 1)));
    updatePower(DRUM_POWER_INCREASE);
    return true;
}
