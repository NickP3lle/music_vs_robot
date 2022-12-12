#include "flute.h"

flute::flute(): music_instrument(100, 100, 1, 100) {};

void flute::level_up() { // bisognerebbe passare la variabile soldi, oppure
						 // facciamo una variabile globale soldi
	// soldi -= 0.5;
	life += 50;
	damage += 50;
	level += 1;
}
