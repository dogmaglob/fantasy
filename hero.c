#include "hero.h"
#include "sdl_utils.h"

struct _hero {
    location * location;
    SDL_Surface * image;
};

hero * hero_new(const char * filename, location * start)
{
    hero * h = malloc(sizeof(hero));
    h->location = start;
    h->image = sdl_utils_load_image(filename);
    return h;
}

void hero_destroy(hero * h)
{
    if (h) {
       SDL_FreeSurface(h->image);
       free(h);
    }
}

void hero_draw(hero * h, SDL_Surface * background)
{
    point origin = location_get_origin(h->location);
    sdl_utils_apply_surface(origin.x, origin.y, h->image, background);
}

