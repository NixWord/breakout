
#ifndef LEVEL_H_
#define LEVEL_H_

#include <string>
#include <vector>

#include <SDL/SDL.h>

#include "Ball.h"
#include "Brick.h"

class Level {
private:
	std::string name;
	SDL_Rect dimensions;
	SDL_Surface* surface;

	std::vector<Brick*>* bricks;

public:
	Level(std::string name, SDL_Rect dimensions);
	~Level();

	int draw(SDL_Surface* screen);

	bool checkBricksCollision(Ball* ball);
	SDL_Rect getDimensions() const;
	std::string getName() const;
	void setDimensions(SDL_Rect dimensions);
	void setName(std::string name);
	std::vector<Brick*> *getBricks() const;
	void setBricks(std::vector<Brick*> *bricks);
};

#endif /* LEVEL_H_ */
