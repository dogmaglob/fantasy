#include <stdlib.h>
#include <string.h>
#include "SDL/SDL_ttf.h"
#include "location.h"
#include "sdl_utils.h"

struct _location {
  point origin;
  SDL_Surface * image;
  TTF_Font * font;
  SDL_Surface * name;
};

location * location_new(const char * filename, const char * name)
{
  location * l = malloc(sizeof(location));
  l->origin.x = 0;
  l->origin.y = 0;
  l->image = sdl_utils_load_image(filename);
  l->font = TTF_OpenFont("./resources/adventure.ttf", 28);
  SDL_Color font_color;
  font_color.r = 0;
  font_color.g = 0;
  font_color.b = 0;
  l->name = TTF_RenderText_Solid(l->font, name, font_color);
  return l;
}

void location_destroy(location * l)
{
  if (l) {
    SDL_FreeSurface(l->image);
    TTF_CloseFont(l->font);
    SDL_FreeSurface(l->name);
    free(l);
  }
}

void location_draw(location * l, point origin, SDL_Surface * background)
{
  sdl_utils_apply_surface(origin.x, origin.y, l->image, background);
  
}

