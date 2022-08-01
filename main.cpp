#include "Game.h"

Game *game = nullptr;

int main(){
    game = new Game();
    game->init();
    while (game->getRunning()) {
        game->eventHandler();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
