#include "Game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game() {}
Game::~Game() {}

SDL_Texture* yoba;

void Game::init(const char* title, int xpos, int ypos, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
    win = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    rnd = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(rnd, 50, 50, 90, 255);
    if (win && rnd){
        std::cout << "initialised!" << std::endl;
        isRunning = true;
    }
    else {
        std::cout << "error occured" << std::endl;
    }
	SDL_Surface * tsurf = SDL_LoadBMP("yoba.bmp");
	yoba = SDL_CreateTextureFromSurface(rnd, tsurf);
	SDL_FreeSurface(tsurf);
}

void Game::eventHandler(){
    SDL_Event e;
    SDL_PollEvent(&e);
    switch (e.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;

    }
}

void Game::render(){
    SDL_RenderClear(rnd);
	SDL_RenderCopy(rnd, yoba, NULL, NULL);
    SDL_RenderPresent(rnd);
}

void Game::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(rnd);
    SDL_Quit();
    std::cout << "game exited" << std::endl;
}

void Game::update(){

}
