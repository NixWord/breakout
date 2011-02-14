#ifndef BRICK_H_
#define BRICK_H_

class Brick {
private:
	SDL_Rect dimensions;

public:
	Brick(SDL_Rect dimensions);
	SDL_Rect getDimensions();
};

#endif /* BRICK_H_ */
