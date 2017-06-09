#include "game.h"
#include "tile.h"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Game::Game(){
  init();
}

void Game::init(){
  running = true;
  SDL_Init(SDL_INIT_EVERYTHING);
  now = SDL_GetTicks();
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
  generateTiles();
  generateMines();
  while(running){
    loop();
  }
}
void Game::generateTiles(){
  for(int i = 0; i < 10; i++){
    for(int k = 0; k < 10; k++){
      Tile temp(getClickedTile(i*20, k*20), i*20, k*20, renderer);
      tiles.push_back(temp);
    }
  }
}
void Game::generateMines(){
  for(int i = 0; i < 10; i++){
    int temp;
    temp = rand() % 99 + 1;
    for(int k = 0; k < mines.size(); k++){
      while(temp == mines[k]){
        temp = rand() % 99 + 1;
      }
    }
    mines.push_back(temp);
  }
  for(int i = 0; i < mines.size(); i++){
    tiles[mines[i]].makeItSoNumberOne();
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
        tileOpen(event.button.x, event.button.y);
      }
    }
  }
}
void Game::tileOpen(int x, int y){
  SDL_Rect temp = {(x/20)*20, (y/20)*20, 20, 20};
  for(int i = 0; i < mines.size(); i++){
    if(getClickedTile(x, y) == mines[i])
    std::cout << "You died. Looser." << std::endl;
  }
  clickedTiles.push_back(temp);
}
int Game::getClickedTile(int x, int y){
  return (y/(WINDOW_HEIGHT/NUM_TILES)*NUM_TILES) + (x/(WINDOW_WIDTH/NUM_TILES));
}
void Game::draw(){
  SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
/*  for(int i = 0; i < NUM_TILES; i++){
    SDL_RenderDrawLine(renderer, 0, 20*i, WINDOW_HEIGHT, 20*i);
    SDL_RenderDrawLine(renderer, 20*i, 0, 20*i, WINDOW_WIDTH);
  }
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  for(int i = 0; i < clickedTiles.size(); i++){
    SDL_RenderFillRect(renderer, &clickedTiles[i]);
  }
*/
  for(int i = 0; i < tiles.size(); i++){
    if(tiles[i].isMine() == 1){
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    else{
      SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
    }
    SDL_Rect temp = tiles[i].getRect();
    SDL_RenderFillRect(renderer, &temp);
    SDL_SetRenderDrawColor(renderer, 0, 255,0, 255);
    SDL_RenderCopy(renderer, tiles[i].getTexture(), NULL, &temp);
  }
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
