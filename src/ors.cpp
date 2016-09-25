#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"
#include "TerrainMap.h"

const int GAME_SCREEN_HEIGHT = 680;
const int GAME_SCREEN_WIDTH = 1360;

SDL_Surface *terrain_0 = NULL;
SDL_Surface *tree_0 = NULL;
SDL_Surface *game_screen = NULL;
SDL_Surface *terrain_alpha_mask_0 = NULL;

void render_map(TerrainMap *game_map, SDL_Surface *screen, SDL_Surface *terrain, SDL_Surface *tree, int global_offset_x, int global_offset_y)
{
    //render terrain tiles:
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            blit_surface(terrain, screen, global_offset_x + game_map->coord_to_virtual_bitmap_x(i,j), global_offset_y + game_map->coord_to_virtual_bitmap_y(i,j));
        }
    }
    // render trees:
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (game_map->get_tree_type(i,j) != 255)
            {
                blit_surface(tree, screen, global_offset_x + game_map->coord_to_virtual_bitmap_x(i,j), global_offset_y + game_map->coord_to_virtual_bitmap_y(i,j));
            }
        }
    }
}

int main(int argc, char* args[])
{
    TerrainMap *game_map = new TerrainMap();
    std::cerr << game_map->get_terrain_type(45,67) << std::endl;
    std::cerr << game_map->get_tree_type(45,67) << std::endl;
    std::cerr << game_map->get_building_type(45,67) << std::endl;

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
    tree_0 = load_image("../gfx_ors/02_trees/000_beech/000_0_00_00_00_beech01.tga");

    render_map(game_map, game_screen, terrain_0, tree_0, 400, 200);


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
