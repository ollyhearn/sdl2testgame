#include "Game.h"
#include "Game.cpp"

Game *game = nullptr;

int main(){
    game = new Game();
    game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900);
    while (game->getRunning()) {
        game->eventHandler();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
