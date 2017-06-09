#include "game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game(){
  init();
}

void Game::init(){
  running = true;
  SDL_Init(SDL_INIT_EVERYTHING);
  now = SDL_GetTicks();
  SDL_CreateWindowAndRenderer(200, 200, SDL_WINDOW_SHOWN, &window, &renderer);
  while(running){
    loop();
  }
}

void Game::input(SDL_Event event){
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      running = false;
    }
  }
}

void Game::draw(){
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  SDL_RenderPresent(renderer);
}

void Game::loop(){
  last = now;
  now = SDL_GetTicks();
  dtime = (double)((now-last)/1000.0f);

  SDL_Delay(20);

  std::cout << "dtime=" << dtime << std::endl;

  SDL_Event event;
  input(event);

  draw();
}

Game::~Game(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
}
