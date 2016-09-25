#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>

SDL_Surface *load_image(std::string file_name)
{

    SDL_Surface* raw_image = NULL;
    SDL_Surface* image_display_format = NULL;

    raw_image = IMG_Load(file_name.c_str());
    SDL_SetColorKey(raw_image, SDL_RLEACCEL, raw_image->format->colorkey);
    if (raw_image == NULL){
        std::cerr << "Error while loading file: " << file_name << std::endl;
        exit(1);

    }
    std::cerr  << "file loaded" << std::endl;
    image_display_format = SDL_DisplayFormat(raw_image);

    if (raw_image == NULL){
        std::cerr << "Error while converting file: " << file_name << std::endl;
        exit(2);
    }
    SDL_SetColorKey(image_display_format, SDL_RLEACCEL, image_display_format->format->colorkey);
    std::cerr << "file converted" << std::endl;
    SDL_FreeSurface(raw_image);
    return image_display_format;
}

void blit_surface(SDL_Surface* surface, SDL_Surface* background, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(surface, NULL, background, &offset);
}
