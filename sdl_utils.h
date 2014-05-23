#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include "SDL/SDL.h"

typedef struct {
  int x;
  int y;
} point;

void          sdl_utils_apply_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination);
SDL_Surface * sdl_utils_load_image(const char * filename);

#endif //__SDL_UTILS_H__
