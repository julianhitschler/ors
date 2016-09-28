#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"
#include "TerrainMap.h"
#include "GameState.h"
#include "GraphicsRecord.h"

GameState::GameState()
{
    //ctor
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cerr << "Failed to initialize SDL." << std::endl;
        exit(3);
    }

    game_screen = SDL_SetVideoMode( GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_RESIZABLE );

    if (game_screen == NULL)
    {
        std::cerr << "Failed to open game screen." << std::endl;
        exit(4);
    }
    SDL_WM_SetCaption("ORS", NULL);

    game_map = new TerrainMap();
    terrain_0 = load_image("../gfx_ors/01_terrains/000_1_00_00_00_graslight.tga");
    tree_0 = load_image("../gfx_ors/02_trees/000_beech/000_0_00_00_00_beech01.tga");

    global_offset_x = (60*game_map->get_map_size())/2;
    global_offset_y = (20*game_map->get_map_size())/2;
    quit_game = false;
    screen_velocity_x = 0;
    screen_velocity_y = 0;
    fullscreen = false;
    //set_fullscreen();

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
    for (int i = 0; i < game_map->get_map_size(); i++)
    {
        for (int j = 0; j < game_map->get_map_size(); j++)
        {
            blit_surface(

                terrain_0,
                game_screen,
                game_map->coord_to_virtual_bitmap_x(i,j) - global_offset_x,
                game_map->coord_to_virtual_bitmap_y(i,j) - global_offset_y

            );
        }
    }
    // render trees:
    for (int i = 0; i < game_map->get_map_size(); i++)
    {
        for (int j = 0; j < game_map->get_map_size(); j++)
        {
            if (game_map->get_tree_type(i,j) != 255)
            {
                //std::cerr << "Tree height:"<< tree_0->h << std::endl;
                blit_surface(

                    tree_0,
                    game_screen,
                    game_map->coord_to_virtual_bitmap_x(i,j) - global_offset_x,
                    game_map->coord_to_virtual_bitmap_y(i,j) - tree_0->h + 35 - global_offset_y

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
        screen_velocity_y = -10;
    }
    else if(key_states[ SDLK_DOWN ])
    {
        screen_velocity_y = 10;
    }
    else {
        screen_velocity_y = 0;
    }

    if(key_states[ SDLK_LEFT ])
    {
        screen_velocity_x = -10;
    }
    else if (key_states[ SDLK_RIGHT ])
    {
        screen_velocity_x = 10;
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

        if( event.type == SDL_VIDEORESIZE )
        {
            game_screen = SDL_SetVideoMode( event.resize.w, event.resize.h, 32, SDL_SWSURFACE | SDL_RESIZABLE );
            if( game_screen == NULL )
            {
               std::cerr << "Error while re-sizing window." << std::endl;
               exit(5);
            }
        }

        if(( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_F1 ))
        {
            set_fullscreen();
        }
        if(( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_ESCAPE ))
        {
            unset_fullscreen();
        }
        if ((event.type == SDL_MOUSEBUTTONUP) && (event.button.button == SDL_BUTTON_LEFT))
        {
            int virtual_bitmap_x = event.button.x + global_offset_x;
            int virtual_bitmap_y = event.button.y + global_offset_y;

            std::cerr << virtual_bitmap_x << ":" << virtual_bitmap_y << std::endl;

            int coord_x = game_map->virtual_bitmap_to_coord_x(virtual_bitmap_x, virtual_bitmap_y);
            int coord_y = game_map->virtual_bitmap_to_coord_y(virtual_bitmap_x, virtual_bitmap_y);

            game_map->plant_tree(coord_x, coord_y);
        }
    }
}

void GameState::mainloop()
{
    /**
    int i = game_map->virtual_bitmap_to_coord_x(180-1, 60-1);
    int j = game_map->virtual_bitmap_to_coord_y(180-1, 60-1);

    std::cerr << i << "," << j << std::endl;

    i = game_map->virtual_bitmap_to_coord_x(3, 60-1);
    j = game_map->virtual_bitmap_to_coord_y(3, 60-1);

    std::cerr << i << "," << j << std::endl;

    i = game_map->virtual_bitmap_to_coord_x(180-1, 1);
    j = game_map->virtual_bitmap_to_coord_y(180-1, 1);

    std::cerr << i << "," << j << std::endl;

    //exit(0);


    GraphicsRecord *gr = new GraphicsRecord();
    std::cerr <<"a\n";
    gr->set_graphics_file("gfx.tga", 2);
    **/

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
    } else if (global_offset_x > game_map->get_map_size()*120 - 50){
        global_offset_x = game_map->get_map_size()*120 - 50;
    }
    if (global_offset_y < -50){
        global_offset_y = -50;
    } else if (global_offset_y > game_map->get_map_size()*40 - 50){
        global_offset_y = game_map->get_map_size()*40 - 50;
    }

    //std::cerr << global_offset_x << "," << global_offset_y << std::endl;
}

void GameState::toggle_fullscreen()
{
    if(fullscreen)
    {
        unset_fullscreen();
    } else {
        set_fullscreen();
    }
}

void GameState::set_fullscreen()
{
    game_screen = SDL_SetVideoMode(

        GAME_SCREEN_WIDTH,
        GAME_SCREEN_HEIGHT,
        32,
        //SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN
        SDL_SWSURFACE | SDL_FULLSCREEN
        );

    if( game_screen == NULL )
    {
        std::cerr << "Error while making window fullscreen." << std::endl;
        exit(6);
    }
    fullscreen = true;
}

void GameState::unset_fullscreen()
{
    game_screen = SDL_SetVideoMode( GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_RESIZABLE );
    fullscreen = false;
}
