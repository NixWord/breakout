
#include <SDL/SDL.h>

#include "Ball.h"
#include "Brick.h"

Brick::Brick(SDL_Rect dimensions) {
	this->dimensions = dimensions;
}

SDL_Rect Brick::getDimensions() {
	return this->dimensions;
}

int Brick::draw(SDL_Surface* surface) {
	return SDL_FillRect(surface, &this->dimensions, 0xCCCCCC);
}

bool Brick::touch(Ball* ball) {
	SDL_Rect ballPosition = ball->getPosition();

	if(ballPosition.x < dimensions.x or
			ballPosition.y < dimensions.y or
			ballPosition.x > dimensions.x + dimensions.w or
			ballPosition.y > dimensions.y + dimensions.h ) {
		return false;
	}
	else {
		return true;
	}
}
