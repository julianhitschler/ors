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
