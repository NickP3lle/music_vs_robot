#include "violin.h"

violin::violin() : MusicInstruments(50, 100){};

void violin::level_up() { // bisognerebbe passare la variabile soldi, oppure
                          // facciamo una variabile globale soldi
    // soldi -= 0.5;
    if (getLevel() < 3) {
        updateHealth(25);
        updatePower(50);
        addLevel();
    }
}
