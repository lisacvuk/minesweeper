#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>

class Game{
public:
  Game();
  ~Game();
private:
  void init();
  void draw();
  void input(SDL_Event event);
  void loop();
  double dtime;
  int last;
  int now;
  bool running;
  SDL_Renderer* renderer;
  SDL_Window* window;
};

#endif
