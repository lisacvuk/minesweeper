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
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
  while(running){
    loop();
  }
}

void Game::input(SDL_Event event){
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      running = false;
    }
    if(event.type == SDL_MOUSEBUTTONDOWN){
      if(event.button.button == SDL_BUTTON_LEFT){
        std::cout << "Left button down! Tile:" << getClickedTile(event.button.x, event.button.y) << std::endl;
      }
    }
  }
}

int Game::getClickedTile(int x, int y){
  return (y/(WINDOW_HEIGHT/NUM_TILES)*NUM_TILES) + (x/(WINDOW_WIDTH/NUM_TILES));
}
void Game::draw(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  for(int i = 0; i < NUM_TILES; i++){
    SDL_RenderDrawLine(renderer, 0, 20*i, WINDOW_HEIGHT, 20*i);
    SDL_RenderDrawLine(renderer, 20*i, 0, 20*i, WINDOW_WIDTH);
  }
  SDL_RenderDrawLine(renderer, 0, 20, 200, 20);

  SDL_RenderPresent(renderer);
}

void Game::loop(){
  last = now;
  now = SDL_GetTicks();
  dtime = (double)((now-last)/1000.0f);

  SDL_Delay(20);

  //std::cout << "dtime=" << dtime << std::endl;

  SDL_Event event;
  input(event);

  draw();
}

Game::~Game(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
}
