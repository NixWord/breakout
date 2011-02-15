#include <SDL/SDL.h>

#include "LevelGenerator.h"
#include "Player.h"

int main(void) {
	SDL_Surface* screen = NULL;

	SDL_Rect applicationSize = {0, 0, 640, 480};

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(applicationSize.w, applicationSize.h, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Breakout", NULL);

	SDL_Rect brickShape = {0, 0, 63, 20};
	LevelGenerator* generator = new LevelGenerator(applicationSize, brickShape);

	Player* player = new Player(applicationSize, 420);
	Ball* ball = player->giveBall();

	Level* defaultLevel = generator->generate();

	SDL_Event event;
	bool loop = true;
	while (loop) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			loop = false;
			break;

		case SDL_MOUSEMOTION:
			player->setPosition(event.motion.x);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				loop = false;
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
		defaultLevel->draw(screen);
		player->draw(screen);
		ball->draw(screen);
		SDL_Flip(screen);
	}

	delete defaultLevel;
	delete player;
	delete ball;

	delete generator;

	SDL_Quit();

	return EXIT_SUCCESS;
}
