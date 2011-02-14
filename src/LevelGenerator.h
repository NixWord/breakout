
#ifndef LEVELGENERATOR_H_
#define LEVELGENERATOR_H_

#include "Level.h"

class LevelGenerator {
private:
	SDL_Rect levelRect;
	SDL_Rect brickRect;

public:
	LevelGenerator(SDL_Rect level, SDL_Rect brick);
	virtual ~LevelGenerator();

	Level* generate();
};

#endif /* LEVELGENERATOR_H_ */
