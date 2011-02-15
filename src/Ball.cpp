#include <cmath>

#include <SDL/SDL.h>

#include "Ball.h"

Ball::Ball(SDL_Rect position, SDL_Rect screenSize) {
	this->position = position;
	this->speed = 0.3;
	this->direction = M_PI/3;
	this->screenSize = screenSize;
}

Ball::~Ball() {
}

void Ball::move(unsigned int elapsedTime) {
	int newX = this->position.x + this->speed * cos(this->direction) * elapsedTime;
	int newY = this->position.y - this->speed * sin(this->direction) * elapsedTime;

	if(newX < 0 or newX > screenSize.w) {
		this->direction = M_PI - this->direction;
	}
	else {
		this->position.x = newX;
	}

	if(newY < 0) {
		this->bounce();
	}
	else {
		this->position.y = newY;
	}
}

SDL_Rect Ball::getPosition() const {
	return position;
}

void Ball::bounce() {
	//TODO empecher les overflows
	this->direction = -this->direction;
}

void Ball::setPosition(SDL_Rect position) {
	this->position = position;
}

void Ball::draw(SDL_Surface* screen) {

	this->fillCircle(screen, position.x, position.y, 6, 0x113322);
}

/**
 * SDL_Surface 32-bit circle-fill algorithm without using trig
 *
 * While I humbly call this "Celdecea's Method", odds are that the
 * procedure has already been documented somewhere long ago.  All of
 * the circle-fill examples I came across utilized trig functions or
 * scanning neighbor pixels.  This algorithm identifies the width of
 * a semi-circle at each pixel height and draws a scan-line covering
 * that width.
 *
 * The code is not optimized but very fast, owing to the fact that it
 * alters pixels in the provided surface directly rather than through
 * function calls.
 *
 * WARNING:  This function does not lock surfaces before altering, so
 * use SDL_LockSurface in any release situation.
 *
 * http://gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles
 */
void Ball::fillCircle(SDL_Surface *surface, int cx, int cy, int radius, Uint32 pixel) {
	// Note that there is more to altering the bitrate of this
	// method than just changing this value.  See how pixels are
	// altered at the following web page for tips:
	//   http://www.libsdl.org/intro.en/usingvideo.html
	static const int BPP = 4;

	double r = (double) radius;

	for (double dy = 1; dy <= r; dy += 1.0) {
		// This loop is unrolled a bit, only iterating through half of the
		// height of the circle.  The result is used to draw a scan line and
		// its mirror image below it.

		// The following formula has been simplified from our original.  We
		// are using half of the width of the circle because we are provided
		// with a center and we need left/right coordinates.

		double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
		int x = cx - dx;

		// Grab a pointer to the left-most pixel for each half of the circle
		Uint8 *target_pixel_a = (Uint8 *) surface->pixels
				+ ((int) (cy + r - dy)) * surface->pitch + x * BPP;
		Uint8 *target_pixel_b = (Uint8 *) surface->pixels
				+ ((int) (cy - r + dy)) * surface->pitch + x * BPP;

		for (; x <= cx + dx; x++) {
			*(Uint32 *) target_pixel_a = pixel;
			*(Uint32 *) target_pixel_b = pixel;
			target_pixel_a += BPP;
			target_pixel_b += BPP;
		}
	}
}
