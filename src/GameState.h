#ifndef GAMESTATE_H
#define GAMESTATE_H

const int GAME_SCREEN_HEIGHT = 680;
const int GAME_SCREEN_WIDTH = 1360;

class GameState
{
    public:
        GameState();
        virtual ~GameState();
        void render_map();
        void flip_sceen();
        void show();
    protected:
    private:
        TerrainMap *game_map;
        SDL_Surface *terrain_0;
        SDL_Surface *tree_0;
        SDL_Surface *game_screen;
        int global_offset_x;
        int global_offset_y;
};

#endif // GAMESTATE_H
