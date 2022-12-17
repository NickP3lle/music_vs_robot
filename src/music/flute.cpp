#include "flute.h"

Flute::Flute() : MusicInstruments(100, 100){};

void Flute::levelUpHealthPower() {
    updateHealth(50);
    updatePower(50);
}