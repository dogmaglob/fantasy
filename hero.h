#ifndef __HERO_H__
#define __HERO_H__

#include "SDL/SDL.h"

typedef struct _hero hero;

hero * hero_new(const char * filename, int x, int y);
void   hero_destroy(hero * h);
void   hero_draw(hero * h, SDL_Surface * background);

#endif //__HERO_H__
