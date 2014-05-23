#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "game.h"

int main(int argc, char * argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("\nUnable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }
  if (TTF_Init() != 0) {
    printf("\nUnable to initialize TTF\n");
    return 1;
  }
  atexit(SDL_Quit);
  game_loop();
  return 0;  
}
