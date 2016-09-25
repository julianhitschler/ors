#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"

const int GAME_SCREEN_HEIGHT = 680;
const int GAME_SCREEN_WIDTH = 1360;

SDL_Surface *terrain_0 = NULL;
SDL_Surface *game_screen = NULL;
SDL_Surface *terrain_alpha_mask_0 = NULL;

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
    terrain_0 = load_image("../gfx_ors/01_terrains/000_1_00_00_00_graslight.tga");
    blit_surface(terrain_0, game_screen, 200, 200);
    blit_surface(terrain_0, game_screen, 320, 200);
    blit_surface(terrain_0, game_screen, 440, 200);

    blit_surface(terrain_0, game_screen, 260, 220);
    blit_surface(terrain_0, game_screen, 260, 180);

    if (SDL_Flip(game_screen) == -1)
    {
        std::cerr << "Game screen could not be opened." << std::endl;
        exit(5);
    }

    SDL_Delay(10000);
    SDL_FreeSurface(terrain_0);
    SDL_Quit();

    std::cerr << "Success!" << std::endl;

    exit(0);
}
