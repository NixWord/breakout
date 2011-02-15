#include <vector>

#include <SDL/SDL.h>

#include "Brick.h"
#include "LevelGenerator.h"

using namespace std;

LevelGenerator::LevelGenerator(SDL_Rect level, SDL_Rect brick) {
	this->levelRect = level;
	this->brickRect = brick;
}

LevelGenerator::~LevelGenerator() {

}

Level* LevelGenerator::generate() {
	Level* level = new Level("Generated Level", this->levelRect);
	vector<Brick*>* bricks = new vector<Brick*>();
	for(int i = 0; i < 5; i++) {
		SDL_Rect newBrickReck = {0, i*40, this->brickRect.w, this->brickRect.h};
		Brick* brick = new Brick(newBrickReck);
		bricks->push_back(brick);
	}
	level->setBricks(bricks);
	return level;
}
