#include "flute.h"

flute::flute() : MusicInstruments(100, 100){};

void flute::levelUpHealth() { updateHealth(50); }

void flute::levelUpPower() { updatePower(50); }