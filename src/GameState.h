#ifndef GAMESTATE_H
#define GAMESTATE_H

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
};

#endif // GAMESTATE_H
