#include "saxophone.h"

saxophone::saxophone() : MusicInstruments(100, 0){};

void saxophone::level_up() { // bisognerebbe passare la variabile soldi, oppure
                             // facciamo una variabile globale soldi
    // soldi -= 1;
    if (getLevel() < 3) {
        updateHealth(100);
        addLevel();
    }
}
