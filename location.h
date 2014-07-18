#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "SDL/SDL.h"
#include "sdl_utils.h"

typedef struct _location location;

typedef enum { 
  LOCATION_TYPE_CITY, 
  LOCATION_TYPE_DUNGEON
} location_type;

location * location_new(const char * filename, const char * name, int x, int y, location_type type);
void       location_destroy(location * l);
void       location_draw(location * l, SDL_Surface * background);
point      location_get_origin(location * l);

#endif //__LOCATION_H__

