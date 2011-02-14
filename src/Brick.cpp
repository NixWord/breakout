
#include <SDL/SDL.h>

#include "Brick.h"

Brick::Brick(SDL_Rect dimensions) {
	this->dimensions = dimensions;
}

SDL_Rect Brick::getDimensions() {
	return this->dimensions;
}
