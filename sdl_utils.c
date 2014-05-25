#include "SDL/SDL_image.h"
#include "sdl_utils.h"

static void apply_clip(int x, int y, SDL_Surface * source, SDL_Surface * destination, SDL_Rect * clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, clip, destination, &offset);
}

void sdl_utils_apply_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination)
{
  apply_clip(x, y, source, destination, NULL);
}

SDL_Surface * sdl_utils_load_image(const char * filename)
{
  SDL_Surface * loaded_image = NULL;
  SDL_Surface * optimized_image = NULL;
  loaded_image = IMG_Load(filename);
  if (loaded_image != NULL) {
    optimized_image = SDL_DisplayFormat(loaded_image);
    SDL_FreeSurface(loaded_image);
    if (optimized_image != NULL) {
      Uint32 color_key = SDL_MapRGB(optimized_image->format, 0, 255, 255);
      SDL_SetColorKey(optimized_image, SDL_SRCCOLORKEY, color_key);
    }
  }
  return optimized_image;
}

