#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "SDL/SDL.h"

typedef struct _location location;

typedef enum { 
  LOCATION_TYPE_CITY, 
  LOCATION_TYPE_DUNGEON,
  LOCATION_TYPE_VILLAGE,
  LOCATION_TYPE_RUINS
} location_type;

location * location_new(const char * filename, const char * name, int x, int y, location_type type);
void       location_destroy(location * l);
void       location_draw(location * l, SDL_Surface * background);

#endif //__LOCATION_H__

