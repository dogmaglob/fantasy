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

location * location_new(const char * filename, const char * name, int x, int y)
{
  location * l = malloc(sizeof(location));
  l->origin.x = x;
  l->origin.y = y;
  l->image = sdl_utils_load_image(filename);
  l->font = TTF_OpenFont("./resources/adventure.ttf", 14);
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

void location_draw(location * l, SDL_Surface * background)
{
  sdl_utils_apply_surface(l->origin.x, l->origin.y, l->image, background);
  point name_origin;
  name_origin.x = l->origin.x + (l->image->w / 2) - (l->name->w / 2);
  name_origin.y = l->origin.y + l->image->h;
  sdl_utils_apply_surface(name_origin.x, name_origin.y, l->name, background); 
}

