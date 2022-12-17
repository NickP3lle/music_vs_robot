#include "saxophone.h"

Saxophone::Saxophone() : MusicInstruments(100, 0){};

void Saxophone::levelUpHealthPower() {
    updateHealth(100);
    updatePower();
}