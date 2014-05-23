#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "board.h"
#include "location.h"
#include "sdl_utils.h"

struct _board {
  unsigned int height;
  unsigned int width;
  unsigned int bpp;
  SDL_Surface * background;
  Uint32 background_color;
  location * castle;
};

static void board_draw_background(board * b)
{
  SDL_FillRect(b->background, &b->background->clip_rect, b->background_color);
}

static void board_draw_locations(board * b)
{
  point origin;
  origin.x = 0;
  origin.y = 0;
  location_draw(b->castle, origin, b->background);
}

board * board_new()
{
  board * b = malloc(sizeof(board));
  b->height = 800;
  b->width = 960; 
  b->bpp = 32; 
  b->background = SDL_SetVideoMode(b->height, b->width, b->bpp, SDL_SWSURFACE);
  SDL_WM_SetCaption("Fantasy", NULL);
  b->background_color = SDL_MapRGB(b->background->format, 0x80, 0x80, 0x80);
  b->castle = location_new("./resources/castle.png", "Bridgewater");
  return b;
}

void board_destroy(board * b)
{
  if (b) {
    SDL_FreeSurface(b->background);
    location_destroy(b->castle);
    free(b);
  }
}

void board_draw(board * b)
{
  board_draw_background(b);
  board_draw_locations(b);
  SDL_Flip(b->background);
}

