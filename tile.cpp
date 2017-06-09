#include "tile.h"
#include <SDL2/SDL_ttf.h>

Tile::Tile(int p_id, int p_x, int p_y, SDL_Renderer* renderer){
  pos = p_id;
  x = p_x;
  y = p_y;
  rect.x = p_x;
  rect.y = p_y;
  rect.w = 20;
  rect.h = 20;
  TTF_Init();
  TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 14);
  SDL_Color White = {255, 255, 255};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "8", White);
  textTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
}
