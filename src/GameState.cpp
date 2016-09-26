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

    global_offset_x = (120*MAP_SIZE)/2;
    global_offset_y = (40*MAP_SIZE)/2;
    quit_game = false;
    screen_velocity_x = 0;
    screen_velocity_y = 0;

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

void GameState::render_map()
{
    //black out screen:
    SDL_FillRect( game_screen, &game_screen->clip_rect, SDL_MapRGB( game_screen->format, 0x00, 0x00, 0x00 ) );
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
                //std::cerr << "Tree height:"<< tree_0->h << std::endl;
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
    //handle key states:
    Uint8 *key_states = SDL_GetKeyState(NULL);

    if( key_states[ SDLK_UP ] )
    {
        screen_velocity_y = 10;
    }
    else if(key_states[ SDLK_DOWN ])
    {
        screen_velocity_y = -10;
    }
    else {
        screen_velocity_y = 0;
    }

    if(key_states[ SDLK_LEFT ])
    {
        screen_velocity_x = 10;
    }
    else if (key_states[ SDLK_RIGHT ])
    {
        screen_velocity_x = -10;
    }
    else {
        screen_velocity_x = 0;
    }

    //handle other events:
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
    double i = game_map->virtual_bitmap_to_coord_x(180-1, 60-1);
    double j = game_map->virtual_bitmap_to_coord_y(180-1, 60-1);

    std::cerr << i << "," << j << std::endl;

    i = game_map->virtual_bitmap_to_coord_x(3, 60-1);
    j = game_map->virtual_bitmap_to_coord_y(3, 60-1);

    std::cerr << i << "," << j << std::endl;

    i = game_map->virtual_bitmap_to_coord_x(180-1, 1);
    j = game_map->virtual_bitmap_to_coord_y(180-1, 1);

    std::cerr << i << "," << j << std::endl;

    //exit(0);

    while(!quit_game)
    {
        render_map();
        flip_sceen();
        SDL_Delay(50);
        handle_events();
        move_global_offset();
    }
}

void GameState::move_global_offset()
{
    global_offset_x += screen_velocity_x;
    global_offset_y += screen_velocity_y;

    if (global_offset_x < -50){
        global_offset_x = -50;
    } else if (global_offset_x > MAP_SIZE*120 + 50){
        global_offset_x = MAP_SIZE*120 + 50;
    }
    if (global_offset_y < -50){
        global_offset_y = -50;
    } else if (global_offset_y > MAP_SIZE*40 + 50){
        global_offset_y = MAP_SIZE*40 + 50;
    }

    //std::cerr << global_offset_x << "," << global_offset_y << std::endl;
}
