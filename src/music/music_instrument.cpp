#include "music_instrument.h"

MusicInstruments::MusicInstruments(u32 life, u32 damage) : Entity(life, damage), level(1){};

u32 MusicInstruments::getLevel() const { return level; }

bool MusicInstruments::levelUp() {
    if (level >= 3) {
        std::cerr << "Level max already reached" << std::endl;
        return false;
    }
    if (!(Cash::getInstance()->sub(getUpdatePrice()))) {
        // std::cerr << "You don't have enough money" << std::endl;
        return false;
    }
    level += 1;

    std::cout << "Succesfully leveled up" << std::endl;
    std::cout << "Level: " << level << std::endl;
}