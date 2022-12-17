#include "saxophone.h"

saxophone::saxophone() : MusicInstruments(100, 0){};

void saxophone::levelUpHealth() { updateHealth(100); }

void saxophone::levelUpPower() { updatePower(); }