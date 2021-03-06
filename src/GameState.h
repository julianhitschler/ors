#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"
#include "TerrainMap.h"
#include "GameState.h"
#include "MapObject.h"
#include "TreeTypeRecord.h"

const int GAME_SCREEN_HEIGHT = 750;
const int GAME_SCREEN_WIDTH = 1350;

//const int GAME_SCREEN_HEIGHT = 500;
//const int GAME_SCREEN_WIDTH = 800;

class GameState
{
    public:
        GameState();
        virtual ~GameState();
        void render_map();
        void flip_sceen();
        void handle_events();
        void mainloop();
        void move_global_offset();
        void toggle_fullscreen();
        void set_fullscreen();
        void unset_fullscreen();
        int locate_event_coord_x(SDL_Event *event);
        int locate_event_coord_y(SDL_Event *event);
        bool tile_visible(int coord_x, int coord_y);
        void get_visible_range(int *values);
        void load_graphics();
        void add_tree_type(TreeTypeRecord *tt, int i);
        void add_graphics(GraphicsRecord *gr);
        void random_trees(int percent);
    protected:
    private:
        TerrainMap *game_map;
        SDL_Surface *terrain_0;
        SDL_Surface *tree_0;
        SDL_Surface *game_screen;
        int global_offset_x;
        int global_offset_y;
        SDL_Event event;
        bool quit_game;
        int screen_velocity_x;
        int screen_velocity_y;
        bool fullscreen;
        int screen_width;
        int screen_height;
        std::vector<GraphicsRecord*> *graphics;
        std::vector<TreeTypeRecord*> *tree_types;
        int tree_type_counter;
};

#endif // GAMESTATE_H
