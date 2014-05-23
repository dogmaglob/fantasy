#include <stdbool.h>
#include "SDL/SDL.h"
#include "game.h"
#include "board.h"
#include "timer.h"

static const unsigned int FRAMES_PER_SECOND = 30;
void game_loop()
{
  board * game_board = board_new();
  timer * fps = timer_new();
  bool quit = false;
  while (!quit) {
    timer_start(fps);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    board_draw(game_board);
    if (timer_get_ticks(fps) < 1000 / FRAMES_PER_SECOND) {
      SDL_Delay((1000 / FRAMES_PER_SECOND) - timer_get_ticks(fps));
    }
  }
  timer_destroy(fps);
  board_destroy(game_board);
}
