#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define NUM_TILES 10

#define WINDOW_HEIGHT 200
#define WINDOW_WIDTH 200

#include <SDL2/SDL.h>

#include <vector>

class Game{
public:
  Game();
  ~Game();
private:
  void init();
  void draw();
  void input(SDL_Event event);
  void loop();
  void tileOpen(int x, int y);
  void generateMines();
  int getClickedTile(int x, int y);
  double dtime;
  int last;
  int now;
  bool running;
  std::vector<SDL_Rect> clickedTiles;
  std::vector<int> mines;
  SDL_Renderer* renderer;
  SDL_Window* window;
};

#endif
