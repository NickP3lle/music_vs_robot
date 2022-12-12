#include "saxophone.h"

saxophone::saxophone(): music_instrument(100, 0, 1, 180) {};

void saxophone::level_up() { // bisognerebbe passare la variabile soldi, oppure
						 // facciamo una variabile globale soldi
	// soldi -= 1;
	life += 100;
	damage += 0;
	level += 1;
}
