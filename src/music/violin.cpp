#include "violin.h"

Violin::Violin() : MusicInstruments(VIOLIN_DEFAULT_HEALTH, 100){};

bool Violin::levelUp() {
    if (!(checkLevelUp(VIOLIN_UPDATE_PRICE))) {
        return false;
    }

    // level è già stato incrementato
    updateHealth(VIOLIN_DEFAULT_HEALTH + (VIOLIN_HEALTH_INCREASE * (getLevel() - 1)));
    updatePower(VIOLIN_POWER_INCREASE);
    return true;
}