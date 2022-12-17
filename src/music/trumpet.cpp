#include "trumpet.h"

trumpet::trumpet() : MusicInstruments(100, 50){};

void trumpet::levelUpHealth() { updateHealth(50); }

void trumpet::levelUpPower() { updatePower(50); }