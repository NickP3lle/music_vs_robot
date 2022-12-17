#include "trumpet.h"

Trumpet::Trumpet() : MusicInstruments(100, 50){};

void Trumpet::levelUpHealthPower() {
    updateHealth(50);
    updatePower(50);
}