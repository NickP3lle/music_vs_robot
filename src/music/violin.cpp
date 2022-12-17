#include "violin.h"

violin::violin() : MusicInstruments(50, 100){};

void violin::levelUpHealth() { updateHealth(25); }

void violin::levelUpPower() { updatePower(50); }