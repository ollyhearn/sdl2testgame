#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Game {

public:
    Game();
    ~Game();

    void init(char title, int xpos, int ypos, int width, int height);
    void eventHandler();
    void update();
    void render();
    void clean();

    bool getRunning() { return isRunning; }

private:
    SDL_Window *win;
    SDL_Renderer *rnd;
    bool isRunning = false;
};

#endif