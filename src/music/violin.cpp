#include "violin.h"

violin::violin() : MusicInstruments(50, 100){};

void violin::level_up() { // bisognerebbe passare la variabile soldi, oppure
                          // facciamo una variabile globale soldi
    // soldi -= 0.5;
    Cash *ptr = Cash::getInstance();
    if (getLevel() < 3 && ptr->getTotal() >= 0.5) {
        ptr->sub(0.5);
        updateHealth(25);
        updatePower(50);
        addLevel();
    } else {
        std::cerr << "You don't have enough money" << std::endl;
    }
}
