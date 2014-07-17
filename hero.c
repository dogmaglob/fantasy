#include "hero.h"
#include "sdl_utils.h"

struct _hero {
    point origin;
    SDL_Surface * image;
};

hero * hero_new(const char * filename, int x, int y)
{
    hero * h = malloc(sizeof(hero));
    h->origin.x = x;
    h->origin.y = y;
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
    sdl_utils_apply_surface(h->origin.x, h->origin.y, h->image, background);
}

