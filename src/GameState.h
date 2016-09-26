#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
        GameState();
        virtual ~GameState();

        void render_map(

            TerrainMap *game_map,
            SDL_Surface *screen,
            SDL_Surface *terrain,
            SDL_Surface *tree,
            int global_offset_x,
            int global_offset_y

        );

    protected:
    private:
        TerrainMap game_map;
};

#endif // GAMESTATE_H
