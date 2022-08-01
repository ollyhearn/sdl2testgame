#include "Game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game() {}
Game::~Game() {}

SDL_Texture* yoba;
SDL_Rect sr, dr;

void Game::init(const char* title, int xpos, int ypos, int width, int height) {
    SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
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
	SDL_Surface * tsurf = IMG_Load("yoba.png");
	if (tsurf == NULL){
		std::cout << "Error loading PNG: " << IMG_GetError() << std::endl;
	}
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
	SDL_RenderCopy(rnd, yoba, NULL, &dr);
    SDL_RenderPresent(rnd);
}

void Game::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(rnd);
    SDL_Quit();
    std::cout << "game exited" << std::endl;
}

void Game::update(){
	sr.h = 64;
	sr.w = 64;
	dr.h = 256;
	dr.w = 256;
//	dr.x += 1;
	if (!direction){
		dr.x += 1;
	}
	else {
		dr.x -= 1;
	}
	if (dr.x == 1600 - dr.h || dr.x == 0){
		direction = !direction;
	}
	//SDL_Delay(2);
}
