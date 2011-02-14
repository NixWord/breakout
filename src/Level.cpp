#include <SDL/SDL.h>
#include <string>

#include "Level.h"

using namespace std;

Level::Level(string name, SDL_Rect dimensions) {
	this->setName(name);
	this->setDimensions(dimensions);
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

