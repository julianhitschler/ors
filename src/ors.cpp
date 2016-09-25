#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>

const int GAME_SCREEN_HEIGHT = 680;
const int GAME_SCREEN_WIDTH = 1360;

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

void blit_surface(SDL_Surface* surface, SDL_Surface* background, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(surface, NULL, background, &offset);
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cerr << "Failed to initialize SDL." << std::endl;
        exit(3);
    }

    game_screen = SDL_SetVideoMode( GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32, SDL_SWSURFACE );

    if (game_screen == NULL)
    {
        std::cerr << "Failed to open game screen." << std::endl;
        exit(4);
    }

    SDL_WM_SetCaption("ORS", NULL);
    terrain0 = load_image("../gfx_ors/01_terrains/000_0_00_00_00_graslight.tga");
    blit_surface(terrain0, game_screen, 200, 200);

    if (SDL_Flip(game_screen) == -1)
    {
        std::cerr << "Game screen could not be opened." << std::endl;
        exit(5);
    }

    SDL_Delay(10000);
    SDL_FreeSurface(terrain0);
    SDL_Quit();

    std::cerr << "Success!" << std::endl;

    exit(0);
}
