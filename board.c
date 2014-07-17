#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "board.h"
#include "location.h"
#include "sdl_utils.h"

#define BOARD_LOCATIONS 15

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
  b->locations[0] = location_new("./resources/city.png", "Bridgewater", 50, 70, LOCATION_TYPE_CITY);
  b->locations[1] = location_new("./resources/castle-dark.png", "Ravenhold", 200, 60, LOCATION_TYPE_CITY);
  b->locations[2] = location_new("./resources/hill-castle.png", "Skyreach", 110, 700, LOCATION_TYPE_CITY);
  b->locations[3] = location_new("./resources/castle.png", "Northern Isles", 400, 50, LOCATION_TYPE_CITY);
  b->locations[4] = location_new("./resources/tower-fantasy.png", "Seawatch", 430, 200, LOCATION_TYPE_CITY);
  b->locations[5] = location_new("./resources/church.png", "Sanctuary", 550, 160, LOCATION_TYPE_CITY);
  b->locations[6] = location_new("./resources/town-1.png", "Highrock", 640, 300, LOCATION_TYPE_CITY);
  b->locations[7] = location_new("./resources/tower-china.png", "Dragonfall", 770, 190, LOCATION_TYPE_CITY);
  b->locations[8] = location_new("./resources/village-2.png", "Southern Isles", 680, 800, LOCATION_TYPE_CITY);
  b->locations[9] = location_new("./resources/city-underground.png", "Sunken City of Yig", 130, 400, LOCATION_TYPE_DUNGEON);
  b->locations[10] = location_new("./resources/pyramids.png", "Tomb of the Burning God", 500, 330, LOCATION_TYPE_DUNGEON);
  b->locations[11] = location_new("./resources/forest2-dense.png", "Elder Woods", 470, 550, LOCATION_TYPE_DUNGEON);
  b->locations[12] = location_new("./resources/mountain-twin.png", "Vaults of Solitude", 620, 20, LOCATION_TYPE_DUNGEON);
  b->locations[13] = location_new("./resources/volcano-active.png", "Mount Diablo", 700, 450, LOCATION_TYPE_DUNGEON);
  b->locations[14] = location_new("./resources/ship.png", "Lost Armada", 350, 820, LOCATION_TYPE_DUNGEON);
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

