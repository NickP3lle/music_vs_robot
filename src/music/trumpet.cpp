#include "trumpet.h"

trumpet::trumpet() : MusicInstruments(100, 50){};

void trumpet::level_up() { // bisognerebbe passare la variabile soldi, oppure
                           // facciamo una variabile globale soldi
    // soldi -= 1;
    if (getLevel() < 3) {
        updateHealth(50);
        updatePower(50);
        addLevel();
    }
}
