#include <SDL/SDL.h>

#include "Player.h"

Player::Player(SDL_Rect screenSize, unsigned int y) {
	int defaultWidth = 100;
	int defaultHeight = 15;

	this->position.x = (screenSize.w - defaultWidth) / 2;
	this->position.y = y;

	this->position.w = defaultWidth;
	this->position.h = defaultHeight;

	this->screenSize = screenSize;
}

Player::~Player() {
}

Ball* Player::giveBall() {
	SDL_Rect ballPos = {this->position.x + (this->position.w / 2), position.y, 0, 0};
	Ball* ball = new Ball(ballPos, screenSize);
	return ball;
}

void Player::setPosition(unsigned short int x) {
	unsigned int short halfwidth = this->position.w / 2;
	if( halfwidth < x and (screenSize.w - halfwidth) > x) {
		this->position.x = x - position.w / 2;
	}
}

void Player::checkCollision(Ball* ball) {
	SDL_Rect ballPosition = ball->getPosition();
	if(ballPosition.x > this->position.x and
			ballPosition.x < this->position.x + this->position.w and
			ballPosition.y > this->position.y and
			ballPosition.y < this->position.y + this->position.h) {
		ball->bounce();
	}
}

int Player::draw(SDL_Surface* screen) {
	return SDL_FillRect(screen, &this->position, 0xDDCCEE);
}
