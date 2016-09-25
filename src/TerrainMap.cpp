#include "TerrainMap.h"

TerrainMap::TerrainMap()
{
    //ctor
    for (int i; i < MAP_SIZE; i++)
    {
        for (int j; j < MAP_SIZE; j++)
        {
            terrain_type[i][j] = 0;
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
