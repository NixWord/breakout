
#ifndef LEVEL_H_
#define LEVEL_H_

#include <SDL/SDL.h>
#include <string>

class Level {
private:
	std::string name;
	SDL_Rect dimensions;
	SDL_Surface* surface;

public:
	Level(std::string name, SDL_Rect dimensions);
	~Level();

	int draw(SDL_Surface* screen);

	SDL_Rect getDimensions() const;
	std::string getName() const;
	void setDimensions(SDL_Rect dimensions);
	void setName(std::string name);
};

#endif /* LEVEL_H_ */