#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "SDL/SDL.h"

typedef struct _location location;

location * location_new(const char * filename, const char * name, int x, int y);
void       location_destroy(location * l);
void       location_draw(location * l, SDL_Surface * background);

#endif //__LOCATION_H__

