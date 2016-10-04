#include "GameState.h"
#include <iostream>
#include "ConfigParser.h"

int main(int argc, char* args[])
{

    GameState *game_state = new GameState();
    ConfigParser config_parser;
    config_parser.parseConfig("../config/ors.config", game_state);
    std::cout << "Loading graphics:" << std::endl;
    game_state->load_graphics();
    std::cout << "Planting random trees:" << std::endl;
    game_state->random_trees(35);
    std::cout << "Starting the game:" << std::endl;
    game_state->mainloop();
    std::cout << "Success!" << std::endl;
    exit(0);
}
