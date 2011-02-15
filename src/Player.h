#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL/SDL.h>

class Player {
private:
	SDL_Rect position;

	SDL_Rect screenSize;

public:
	Player(SDL_Rect screenSize, unsigned int y);
	virtual ~Player();

	int draw(SDL_Surface* screen);
	void setPosition(unsigned short int x);
};

#endif /* PLAYER_H_ */
