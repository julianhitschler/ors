#include "GameState.h"

GameState::GameState()
{
    //ctor
    screen_width = GAME_SCREEN_WIDTH;
    screen_height = GAME_SCREEN_HEIGHT;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cerr << "Failed to initialize SDL." << std::endl;
        exit(3);
    }

    game_screen = SDL_SetVideoMode( screen_width, screen_height, 32, SDL_SWSURFACE | SDL_RESIZABLE );

    if (game_screen == NULL)
    {
        std::cerr << "Failed to open game screen." << std::endl;
        exit(4);
    }
    SDL_WM_SetCaption("ORS", NULL);

    tree_types = new std::vector<TreeTypeRecord*>(256, NULL);
    tree_type_counter = 0;
    graphics = new std::vector<GraphicsRecord*>(10000, NULL);

    game_map = new TerrainMap();
    terrain_0 = load_image("../gfx_ors/01_terrains/000_1_00_00_00_graslight.tga");

    global_offset_x = (60*game_map->get_map_size())/2;
    global_offset_y = (20*game_map->get_map_size())/2;
    quit_game = false;
    screen_velocity_x = 0;
    screen_velocity_y = 0;
    fullscreen = false;
    set_fullscreen();

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
    //Get the visible range:
    int visible_range[] = {0,0,0,0};
    get_visible_range(visible_range);

    int x_begin = visible_range[0];
    int x_end = visible_range[1];
    int y_begin = visible_range[2];
    int y_end = visible_range[3];

    //black out screen:
    SDL_FillRect( game_screen, &game_screen->clip_rect, SDL_MapRGB( game_screen->format, 0x00, 0x00, 0x00 ) );
    //render terrain tiles:
    for (int i = x_begin; i <= x_end; i++)
    {
        for (int j = y_begin; j <= y_end; j++)
        {
                blit_surface(

                    terrain_0,
                    game_screen,
                    game_map->coord_to_virtual_bitmap_x(i,j) - global_offset_x,
                    game_map->coord_to_virtual_bitmap_y(i,j) - global_offset_y

                );
        }
    }
    // render map objects:
    //std::cout << "D\n";
    unsigned short display_object_status;
    MapObject *mo = NULL;
    MapObjectTypeRecord * motr = NULL;
    GraphicsRecord *gr = NULL;
    //std::cout << "C\n";
    for (int i = x_begin; i <= x_end; i++)
    {
        for (int j = y_begin; j <= y_end; j++)
        {
                mo = game_map->get_map_object(i,j);
                //std::cout << "E\n";
                display_object_status = game_map->get_display_object(i,j);
                if (mo != NULL && display_object_status == 1)
                {
                    //std::cout << "A\n";
                    motr = mo->get_type_record();
                    gr = motr->get_graphics_record();

                    blit_surface(

                        gr->get_graphics(0),
                        game_screen,
                        game_map->coord_to_virtual_bitmap_x(i,j) + motr->get_offset_x() - global_offset_x,
                        game_map->coord_to_virtual_bitmap_y(i,j) + motr->get_offset_y() - gr->get_graphics(0)->h - global_offset_y

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
    if (key_states[ SDLK_q])
    {
        quit_game = true;
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
            screen_width = event.resize.w;
            screen_height = event.resize.h;
            game_screen = SDL_SetVideoMode( screen_width, screen_height, 32, SDL_SWSURFACE | SDL_RESIZABLE );
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
            game_map->plant_tree(locate_event_coord_x(&event), locate_event_coord_y(&event), tree_types->at(0));
        }
        if ((event.type == SDL_MOUSEBUTTONUP) && (event.button.button == SDL_BUTTON_RIGHT))
        {
            game_map->remove_tree(locate_event_coord_x(&event), locate_event_coord_y(&event));
        }
    }
}

int GameState::locate_event_coord_x(SDL_Event *event)
{
        int virtual_bitmap_x = event->button.x + global_offset_x;
        int virtual_bitmap_y = event->button.y + global_offset_y;
        return game_map->virtual_bitmap_to_coord_x(virtual_bitmap_x, virtual_bitmap_y);
}

int GameState::locate_event_coord_y(SDL_Event *event)
{
        int virtual_bitmap_x = event->button.x + global_offset_x;
        int virtual_bitmap_y = event->button.y + global_offset_y;
        return game_map->virtual_bitmap_to_coord_y(virtual_bitmap_x, virtual_bitmap_y);
}

void GameState::mainloop()
{
    while(!quit_game)
    {
        render_map();
        flip_sceen();
        SDL_Delay(40);
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
    game_screen = SDL_SetVideoMode( screen_width, screen_height, 32, SDL_SWSURFACE | SDL_RESIZABLE );
    fullscreen = false;
}

bool GameState::tile_visible(int coord_x, int coord_y)
{
    int virtual_bitmap_x = game_map->coord_to_virtual_bitmap_x(coord_x, coord_y);
    int virtual_bitmap_y = game_map->coord_to_virtual_bitmap_y(coord_x, coord_y);

    if (virtual_bitmap_x < global_offset_x -1000)
    {
        return false;
    }
    if (virtual_bitmap_x > global_offset_x + screen_width+1000)
    {
        return false;
    }
    if (virtual_bitmap_y < global_offset_y -1000)
    {
        return false;
    }
    if (virtual_bitmap_y > global_offset_y + screen_height+1000)
    {
        return false;
    }
    return true;
}

void GameState::get_visible_range(int values[])
{
    int x_1 = game_map->virtual_bitmap_to_coord_x(global_offset_x -1000, global_offset_y -1000);
    int x_2 = game_map->virtual_bitmap_to_coord_x(global_offset_x + screen_width + 1000, global_offset_y + screen_height + 1000);
    int y_1 = game_map->virtual_bitmap_to_coord_y(global_offset_x -1000, global_offset_y -1000);
    int y_2 = game_map->virtual_bitmap_to_coord_y(global_offset_x + screen_width +1000, global_offset_y + screen_height + 1000);

    if (x_1 < x_2)
    {
        values[0] = x_1;
        values[1] = x_2;
    } else {
        values[0] = x_2;
        values[1] = x_1;
    }

    if (y_1 < y_2)
    {
        values[2] = y_1;
        values[3] = y_2;
    } else {
        values[2] = y_2;
        values[3] = y_1;
    }
}

void GameState::load_graphics()
{
    for (GraphicsRecord* gr : *graphics)
    {
        if (gr != NULL)
        {
            if (gr->get_graphics(0) == NULL)
            {
                SDL_Surface* image = load_image(*gr->get_graphics_file_name(0));
                gr->set_graphics(image,0);
            }
        }
    }
}

void GameState::add_tree_type(TreeTypeRecord *tt, int i)
{
    if (tree_types->size() <= i){
        std::cerr << "Tree Type buffer size exceeded:" << i << std::endl;
    } else {
        tree_types->at(i) = tt;
        add_graphics(tt->get_graphics_record());
        if (tree_type_counter < tt->get_id())
        {
            tree_type_counter = tt->get_id();
        }
    }
}

void GameState::add_graphics(GraphicsRecord *gr)
{
    int i = 0;
    GraphicsRecord* comp = graphics->at(0);
    while (comp != NULL){
            i++;
            comp = graphics->at(i);
    }
    graphics->at(i) = gr;
}

void GameState::random_trees(int percent)
{
    std::random_device rd;
    std::mt19937 eng(rd()); //seed random generator
    std::uniform_int_distribution<> distr_decision(0, 100);
    std::uniform_int_distribution<> distr_type(0, tree_type_counter);
    int k;
    int t;
    for (int i = 0; i < game_map->get_map_size(); i++)
    {
        for (int j = 0; j < game_map->get_map_size(); j++)
        {
            k = distr_decision(eng);
            if (k <= percent)
            {
                t = distr_type(eng);
                //std::cerr << t << std::endl;
                game_map->plant_tree(i, j, tree_types->at(t));
            }
        }
    }
}
