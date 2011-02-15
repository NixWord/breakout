#ifndef BRICK_H_
#define BRICK_H_

#include <SDL/SDL.h>

#include "Ball.h"

class Brick {
private:
	SDL_Rect dimensions;

public:
	Brick(SDL_Rect dimensions);
	SDL_Rect getDimensions();

	int draw(SDL_Surface* surface);
	bool touch(Ball* ball);
};

#endif /* BRICK_H_ */
