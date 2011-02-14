
#include <SDL/SDL.h>

#include "Brick.h"

Brick::Brick(SDL_Rect dimensions) {
	this->dimensions = dimensions;
}

SDL_Rect Brick::getDimensions() {
	return this->dimensions;
}

int Brick::draw(SDL_Surface* surface) {
	return SDL_FillRect(surface, &this->dimensions, 0xFF000000);
}
