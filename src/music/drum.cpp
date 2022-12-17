#include "drum.h"

drum::drum() : MusicInstruments(200, 300){};

void drum::level_up() { // bisognerebbe passare la variabile soldi, oppure
                        // facciamo una variabile globale soldi
    // soldi -= 0.5;
    if (getLevel() < 3) {
        updateHealth(50);
        updatePower(100);
        addLevel();
    }
}
