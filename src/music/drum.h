#include "music_instrument.h"

#ifndef DRUM_H
#define DRUM_H
class drum: public music_instrument {
	public:
		drum();
		void level_up();
};
#endif
