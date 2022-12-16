#include "flute.h"

flute::flute() : MusicInstruments(100, 100){};

void flute::level_up() { // bisognerebbe passare la variabile soldi, oppure
                         // facciamo una variabile globale soldi
    // soldi -= 0.5;
    if (getLevel() < 3) {
        setHealth(50);
        setPower(50);
        addLevel();
    }
}