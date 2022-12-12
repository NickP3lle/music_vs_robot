#include "drum.h"

drum::drum(): music_instrument(200, 300, 1, 300) {};

void drum::level_up() { // bisognerebbe passare la variabile soldi, oppure
						 // facciamo una variabile globale soldi
	// soldi -= 0.5;
	life += 1;
	damage += 100;
	level += 1;
}
