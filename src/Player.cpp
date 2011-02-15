#include <SDL/SDL.h>

#include "Player.h"

Player::Player(SDL_Rect screenSize, unsigned int y) {
	int defaultWidth = 90;
	int defaultHeight = 20;

	this->position.x = (screenSize.w - defaultWidth) / 2;
	this->position.y = y;

	this->position.w = defaultWidth;
	this->position.h = defaultHeight;
}

Player::~Player() {
}

int Player::draw(SDL_Surface* screen) {
	return SDL_FillRect(screen, &this->position, 0xDDCCEE);
}
