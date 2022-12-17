#include "drum.h"

Drum::Drum() : MusicInstruments(200, 300) {}

void Drum::levelUpHealthPower() {
    updateHealth(50);
    updatePower(100);
}