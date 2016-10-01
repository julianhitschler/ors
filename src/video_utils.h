#ifndef VIDEO_UTILS_H_INCLUDED
#define VIDEO_UTILS_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>

SDL_Surface *load_image(std::string file_name);
void blit_surface(SDL_Surface* surface, SDL_Surface* background, int x, int y);

#endif // VIDEO_UTILS_H_INCLUDED
