#include "GameState.h"
#include <iostream>

int main(int argc, char* args[])
{

    GameState *game_state = new GameState();

    GraphicsRecord *gr = new GraphicsRecord();
    gr->set_graphics_file_name("../gfx_ors/02_trees/000_beech/000_0_00_00_00_beech01.tga", 0);
    TreeTypeRecord *ttr = new TreeTypeRecord();
    ttr->set_graphics_record(gr);
    ttr->set_offset_x(0);
    ttr->set_offset_y(55);
    ttr->set_type_index(0);
    ttr->set_wood_initial(30);

    game_state->add_tree_type(ttr);
    std::cerr << "L\n";
    game_state->load_graphics();

    game_state->mainloop();

    std::cerr << "Success!" << std::endl;

    exit(0);
}
