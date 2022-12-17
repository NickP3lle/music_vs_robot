#include "music_instrument.h"

MusicInstruments::MusicInstruments(u32 life, u32 damage) : Entity(life, damage), level(1){};

// u32 MusicInstruments::getLevel() const { return level; }

void MusicInstruments::levelUp() {
    if (level /*getLevel()*/ >= 3) {
        std::cerr << "Level max already reached" << std::endl;
        return;
    }
    Cash *ptr = Cash::getInstance();
    if (ptr->getTotal() < 50) {
        std::cerr << "You don't have enough money" << std::endl;
        return;
    }

    // Upgrading here
    ptr->sub(50);
    levelUpHealthPower();
    level += 1;

    std::cout << "Succesfully leveled up" << std::endl;
    std::cout << "Level: " << level << std::endl;
}