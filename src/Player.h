#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL/SDL.h>

class Player {
private:
	SDL_Rect position;

public:
	Player(SDL_Rect screenSize, unsigned int y);
	virtual ~Player();

	int draw(SDL_Surface* screen);
};

#endif /* PLAYER_H_ */
