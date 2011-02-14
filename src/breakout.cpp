#include <SDL/SDL.h>

int main(void) {
	SDL_Surface* screen = NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Breakout", NULL);

	bool loop = true;
	while (loop) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			loop = false;
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
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
