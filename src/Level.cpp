#include <SDL/SDL.h>
#include <string>

#include "Level.h"

using namespace std;

Level::Level(string name, SDL_Rect dimensions) {
	this->setName(name);
	this->setDimensions(dimensions);

	this->surface = SDL_CreateRGBSurface(SDL_HWSURFACE, dimensions.x, dimensions.y, 32, 0, 0, 0, 0);
}

static bool deleteAll(Brick* theElement) {
	delete theElement;
	return true;
}

Level::~Level() {
	SDL_FreeSurface(this->surface);

	while(!bricks->empty()) delete bricks->back(), bricks->pop_back();

	delete bricks;
}

int Level::draw(SDL_Surface* screen) {
	return SDL_BlitSurface(this->surface, NULL, screen, NULL);
}

SDL_Rect Level::getDimensions() const {
	return dimensions;
}

string Level::getName() const {
	return name;
}

void Level::setDimensions(SDL_Rect dimensions) {
	this->dimensions = dimensions;
}

void Level::setName(string name) {
	this->name = name;
}

std::vector<Brick*>* Level::getBricks() const {
	return bricks;
}

void Level::setBricks(std::vector<Brick*> *bricks) {
	this->bricks = bricks;
}

