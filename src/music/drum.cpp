#include "drum.h"

drum::drum() : MusicInstruments(200, 300) {}

void drum::level_up() {
    // soldi -= 0.5;
    Cash *ptr = Cash::getInstance();
    if (getLevel() < 3 && ptr->getTotal() >= 0.5) {
        ptr->sub(0.5);
        updateHealth(50);
        updatePower(100);
        addLevel();
    } else {
        std::cerr << "You don't have enough money" << std::endl;
    }
}
