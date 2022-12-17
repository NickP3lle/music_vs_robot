#include "trumpet.h"

trumpet::trumpet() : MusicInstruments(100, 50){};

void trumpet::level_up() { // bisognerebbe passare la variabile soldi, oppure
                           // facciamo una variabile globale soldi
    // soldi -= 1;
    Cash *ptr = Cash::getInstance();
    if (getLevel() < 3 && ptr->getTotal() >= 1) {
        ptr->sub(1);
        updateHealth(50);
        updatePower(50);
        addLevel();
    } else {
        std::cerr << "You don't have enough money" << std::endl;
    }
}
