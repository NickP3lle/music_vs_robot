#include "flute.h"

flute::flute() : MusicInstruments(100, 100){};

void flute::level_up() { // bisognerebbe passare la variabile soldi, oppure
                         // facciamo una variabile globale soldi
    // soldi -= 0.5;
    if (getLevel() < 3) {
        updateHealth(50);
        updatePower(50);
        addLevel();
    }
}