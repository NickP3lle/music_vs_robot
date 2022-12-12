#include "trumpet.h"

trumpet::trumpet(): music_instrument(100, 50, 1, 150) {};

void trumpet::level_up() { // bisognerebbe passare la variabile soldi, oppure
						 // facciamo una variabile globale soldi
	// soldi -= 1;
	life += 50;
	damage += 50;
	level += 1;
}
