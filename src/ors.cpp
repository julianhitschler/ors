#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "video_utils.h"
#include "TerrainMap.h"
#include "GameState.h"

int main(int argc, char* args[])
{

    GameState *game_state = new GameState();

    game_state->render_map();
    game_state->flip_sceen();
    game_state->show();

    std::cerr << "Success!" << std::endl;

    exit(0);
}
