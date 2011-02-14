#include <SDL/SDL.h>

#include "LevelGenerator.h"

LevelGenerator::LevelGenerator(SDL_Rect level, SDL_Rect brick) {
	this->levelRect = level;
	this->brickRect = brick;
}

LevelGenerator::~LevelGenerator() {

}

Level* LevelGenerator::generate() {
	Level* level = new Level("Generated Level", this->levelRect);
	return level;
}
