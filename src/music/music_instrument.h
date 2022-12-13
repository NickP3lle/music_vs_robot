#include "../entity.h"

#ifndef MUSIC_INSTRUMENT_H
#define MUSIC_INSTRUMENT_H
class music_instrument: public entity {
	public:
		unsigned short int level;
		unsigned int price;
		music_instrument(int, int, int =1, int =1);
		virtual void level_up() =0;
};
#endif
