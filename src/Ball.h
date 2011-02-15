#include <SDL/SDL.h>

#ifndef BALL_H_
#define BALL_H_

class Ball {
private:
	SDL_Rect position;
	double speed;
	double direction;

public:
	Ball(SDL_Rect position);
	virtual ~Ball();

	void move(unsigned int elapsedTime);

	void fillCircle(SDL_Surface *surface, int cx, int cy, int radius, Uint32 pixel);
	void draw(SDL_Surface* screen);
};

#endif /* BALL_H_ */
