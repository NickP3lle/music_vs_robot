#include "music_instrument.h"

MusicInstruments::MusicInstruments(u32 life, u32 damage) : Entity(life, damage), level(1){};

void MusicInstruments::addLevel() { level += 1; }

u32 MusicInstruments::getLevel() const { return level; }