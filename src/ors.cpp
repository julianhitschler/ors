#include "GameState.h"
#include <iostream>
#include "parser_utils.h"
#include "ConfigParser.h"

int main(int argc, char* args[])
{

    GameState *game_state = new GameState();
    ConfigParser config_parser;
    config_parser.parseConfig("../config/ors.config", game_state);

    game_state->random_trees();
    game_state->load_graphics();
    game_state->mainloop();

    std::cerr << "Success!" << std::endl;

    exit(0);
}
