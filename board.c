#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "board.h"
#include "location.h"
#include "sdl_utils.h"

#define BOARD_LOCATIONS 9

struct _board {
  unsigned int height;
  unsigned int width;
  unsigned int bpp;
  SDL_Surface * background;
  Uint32 background_color;
  location * castle;
  location * locations[BOARD_LOCATIONS];
};

static void board_draw_background(board * b)
{
  SDL_FillRect(b->background, &b->background->clip_rect, b->background_color);
}

static void board_draw_locations(board * b)
{
  int i;
  for (i = 0; i < BOARD_LOCATIONS; i++) {
    location_draw(b->locations[i], b->background);
  }
}

board * board_new()
{
  board * b = malloc(sizeof(board));
  b->height = 960;
  b->width = 960; 
  b->bpp = 32; 
  b->background = SDL_SetVideoMode(b->height, b->width, b->bpp, SDL_SWSURFACE);
  SDL_WM_SetCaption("Fantasy", NULL);
  b->background_color = SDL_MapRGB(b->background->format, 255, 255, 255);
  b->locations[0] = location_new("./resources/city.png", "Bridgewater", 50, 70);
  b->locations[1] = location_new("./resources/castle-dark.png", "Ravenhold", 200, 60);
  b->locations[2] = location_new("./resources/hill-castle.png", "Skyreach", 110, 700);
  b->locations[3] = location_new("./resources/castle.png", "Northern Isles", 400, 50);
  b->locations[4] = location_new("./resources/tower-fantasy.png", "Seawatch", 430, 200);
  b->locations[5] = location_new("./resources/church.png", "Sanctuary", 550, 160);
  b->locations[6] = location_new("./resources/town-1.png", "Highrock", 640, 300);
  b->locations[7] = location_new("./resources/tower-china.png", "Dragonfall", 770, 190);
  b->locations[8] = location_new("./resources/village-2.png", "Southern Isles", 680, 800);
  return b;
}

void board_destroy(board * b)
{
  if (b) {
    SDL_FreeSurface(b->background);
    int i;
    for (i = 0; i < BOARD_LOCATIONS; i++) {
      location_destroy(b->locations[i]);
    }
    free(b);
  }
}

void board_draw(board * b)
{
  board_draw_background(b);
  board_draw_locations(b);
  SDL_Flip(b->background);
}

