#include "Game.h"
#include "Game.cpp"

Game *game = nullptr;

int main(){
	const int FPS = 60;
	const int fdelay = 1000 / FPS;

	Uint32 fstart;
	int ftime;

    game = new Game();
    game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900);
    while (game->getRunning()) {
		fstart = SDL_GetTicks();
        game->eventHandler();
        game->update();
        game->render();

		ftime = SDL_GetTicks() - fstart;
		if (fdelay > ftime){
			SDL_Delay(fdelay - ftime);
		}
    }

    game->clean();
    return 0;
}
