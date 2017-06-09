#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <SDL2/SDL.h>

class Tile{
public:
  Tile(int p_id, int p_x, int p_y, SDL_Renderer* renderer);
  inline int getX(){
    return x;
  }
  inline int getY(){
    return y;
  }
  inline int getPos(){
    return pos;
  }
  inline SDL_Rect getRect(){
    return rect;
  }
  inline bool isMine(){
    return is_mine;
  }
  inline void makeItSoNumberOne(){
    is_mine = 1;
  }
  inline SDL_Texture* getTexture(){
    return textTexture;
  }
private:
  int pos, x, y;
  bool is_mine = false;
  SDL_Rect rect;
  SDL_Texture* textTexture;
};

#endif
