#include "TerrainMap.h"
#include <iostream>

TerrainMap::TerrainMap()
{
    //ctor
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            terrain_type[i][j] = 0;
            tree_type[i][j] = 255;
            building_type[i][j] = 0;
        }
    }

    //tree_type[0][0] = 0;
    //tree_type[MAP_SIZE-1][0] = 0;
    tree_type[0][MAP_SIZE-1] = 0;
    tree_type[1][MAP_SIZE-1] = 0;
    tree_type[2][MAP_SIZE-1] = 0;
    //tree_type[2][1] = 0;
    tree_type[1][1] = 0;

    //tree_type[MAP_SIZE-1][MAP_SIZE-1] = 0;
}

TerrainMap::~TerrainMap()
{
    //dtor
}

int TerrainMap::get_terrain_type(int x, int y){
    return terrain_type[x][y];
}

int TerrainMap::get_tree_type(int x, int y){
    return tree_type[x][y];
}

int TerrainMap::get_building_type(int x, int y){
    return building_type[x][y];
}

int TerrainMap::coord_to_virtual_bitmap_x(int x, int y){
    // tile_offset = (x-y)
    // center line = MAP_SIZE/2
    return ((MAP_SIZE/2)-(x-y))*60;
}

int TerrainMap::coord_to_virtual_bitmap_y(int x, int y){
    return x*20 + y*20;
}
