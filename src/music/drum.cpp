#include "drum.h"

drum::drum() : MusicInstruments(200, 300) {}

void drum::levelUpHealth() { updateHealth(50); }

void drum::levelUpPower() { updatePower(100); }