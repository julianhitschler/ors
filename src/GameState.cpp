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

    game_map = new TerrainMap();
    terrain_0 = load_image("../gfx_ors/01_terrains/000_1_00_00_00_graslight.tga");
    tree_0 = load_image("../gfx_ors/02_trees/000_beech/000_0_00_00_00_beech01.tga");

    global_offset_x = 200;
    global_offset_y = 100;

    quit_game = false;

}

GameState::~GameState()
{
    //dtor
    delete &game_map;
    SDL_FreeSurface(terrain_0);
}

void GameState::flip_sceen()
{
    if (SDL_Flip(game_screen) == -1)
    {
        std::cerr << "Game screen could not be opened." << std::endl;
        exit(5);
    }
}

void GameState::show()
{
    SDL_Delay(10000);
    SDL_Quit();
}

void GameState::render_map()
{
    //render terrain tiles:
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            blit_surface(

                terrain_0,
                game_screen,
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
                std::cerr << tree_0->h << std::endl;
                blit_surface(

                    tree_0,
                    game_screen,
                    global_offset_x + game_map->coord_to_virtual_bitmap_x(i,j),
                    global_offset_y - tree_0->h + 35 + game_map->coord_to_virtual_bitmap_y(i,j)

                    );
            }
        }
    }
}

void GameState::handle_events()
{
    while (SDL_PollEvent( &event ))
    {
        if( event.type == SDL_QUIT )
        {
            quit_game = true;
        }
    }
}

void GameState::mainloop()
{
    while(!quit_game)
    {
        render_map();
        flip_sceen();
        SDL_Delay(50);
        handle_events();
    }
}
