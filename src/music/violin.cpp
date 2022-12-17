#include "violin.h"

Violin::Violin() : MusicInstruments(50, 100){};

void Violin::levelUpHealthPower() {
    updateHealth(25);
    updatePower(50);
}