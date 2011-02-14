#ifndef BRICK_H_
#define BRICK_H_

class Brick {
private:
	SDL_Rect dimensions;

public:
	Brick(SDL_Rect dimensions);
	SDL_Rect getDimensions();

	int draw(SDL_Surface* surface);
};

#endif /* BRICK_H_ */
