#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>

const int GAME_SCREEN_HEIGHT = 800;
const int GANE_SCREEN_WIDTH = 1200;

SDL_Surface *terrain0 = NULL;
SDL_Surface *game_screen = NULL;

SDL_Surface *load_image(std::string file_name)
{

    SDL_Surface* raw_image = NULL;
    SDL_Surface* image_display_format = NULL;

    raw_image = IMG_Load(file_name.c_str());

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
    std::cerr << "file converted" << std::endl;
    SDL_FreeSurface(raw_image);
    return image_display_format;
}

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    terrain0 = load_image("../gfx_ors/01_terrains/000_0_00_00_00_graslight.tga");
    std::cerr << "Success!" << std::endl;

    exit(0);
}
