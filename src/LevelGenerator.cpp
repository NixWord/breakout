#include <vector>

#include <SDL/SDL.h>

#include "Brick.h"
#include "LevelGenerator.h"

using namespace std;

LevelGenerator::LevelGenerator(SDL_Rect level, SDL_Rect brick) {
	this->levelRect = level;
	this->brickRect = brick;
	this->brickSpacing = 1;
	this->numberOfLines = 4;
}

LevelGenerator::~LevelGenerator() {

}

Level* LevelGenerator::generate() {
	Level* level = new Level("Generated Level", this->levelRect);

	unsigned int maxBricksPerLine = (unsigned int) (levelRect.w / (brickRect.w + brickSpacing));

	vector<Brick*>* bricks = new vector<Brick*>();

	for(unsigned int j = 0; j < numberOfLines; j++) {
		for(unsigned int i = 0; i < maxBricksPerLine; i++) {
			SDL_Rect newBrickReck = {i*(brickSpacing+this->brickRect.w) + brickSpacing, j*(brickSpacing+this->brickRect.h) + brickSpacing, this->brickRect.w, this->brickRect.h};
			Brick* brick = new Brick(newBrickReck);
			bricks->push_back(brick);
		}
	}
	level->setBricks(bricks);

	return level;
}
