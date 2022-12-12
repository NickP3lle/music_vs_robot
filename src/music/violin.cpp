#include "violin.h"

violin::violin(): music_instrument(50, 100, 1, 200) {};

void violin::level_up() { // bisognerebbe passare la variabile soldi, oppure
						 // facciamo una variabile globale soldi
	// soldi -= 0.5;
	life += 25;
	damage += 50;
	level += 1;
}
