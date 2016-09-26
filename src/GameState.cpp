#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"
#include "TerrainMap.h"
#include "GameState.h"

GameState::GameState()
{
    //ctor
    TerrainMap *game_map = new TerrainMap();
}

GameState::~GameState()
{
    //dtor
    delete &game_map;
}

void GameState::render_map(

    TerrainMap *game_map,
    SDL_Surface *screen,
    SDL_Surface *terrain,
    SDL_Surface *tree,
    int global_offset_x,
    int global_offset_y

    )
{
    //render terrain tiles:
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            blit_surface(

                terrain,
                screen,
                global_offset_x + game_map->coord_to_virtual_bitmap_x(i,j),
                global_offset_y + game_map->coord_to_virtual_bitmap_y(i,j)

            );
        }
    }
    // render trees:
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (game_map->get_tree_type(i,j) != 255)
            {
                std::cerr << tree->h << std::endl;
                blit_surface(

                    tree,
                    screen,
                    global_offset_x + game_map->coord_to_virtual_bitmap_x(i,j),
                    global_offset_y - tree->h + 35 + game_map->coord_to_virtual_bitmap_y(i,j)

                    );
            }
        }
    }
}
