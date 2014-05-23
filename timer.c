#include <stdbool.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "timer.h"

struct _timer {
  int start_ticks;
  int paused_ticks;
  bool started;
  bool paused;
};

timer * timer_new()
{
  timer * t = malloc(sizeof(timer));
  t->start_ticks = 0;
  t->started = false;
  return t;
}

void timer_destroy(timer * t)
{
  if (t) {
    free(t);
  }
}

void timer_start(timer * t)
{
  t->started = true;
  t->start_ticks = SDL_GetTicks();
}

int timer_get_ticks(timer * t)
{
  if (t->started = true) {
    return (SDL_GetTicks() - t->start_ticks);
  }
  return 0;
}

