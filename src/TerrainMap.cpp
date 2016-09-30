#include "TerrainMap.h"
#include <iostream>

TerrainMap::TerrainMap()
{
    //ctor
    map_size = 1024;

    terrain_type = std::vector<std::vector<unsigned short> >(map_size);
    tree_type = std::vector<std::vector<unsigned short> >(map_size);
    building_type = std::vector<std::vector<unsigned short> >(map_size);
    map_objects = std::vector<std::vector<MapObject*> >(map_size);

    //std::cerr << "CC\n" << std::endl;

    std::vector<unsigned short> tt_tmp;
    std::vector<unsigned short> trt_tmp ;
    std::vector<unsigned short> bt_tmp ;
    std::vector<MapObject*> mo ;

    //std::cerr << "AA\n";

    for (int i = 0; i < map_size; i++)
    {

        //std::cerr << "BB\n";

        tt_tmp = std::vector<unsigned short>(map_size);
        trt_tmp = std::vector<unsigned short>(map_size);
        bt_tmp = std::vector<unsigned short>(map_size);
        mo = std::vector<MapObject*>(map_size);

        //std::cerr << "DD\n";

        terrain_type.at(i) = (tt_tmp);
        tree_type.at(i) = (trt_tmp);
        building_type.at(i) = (bt_tmp);
        map_objects.at(i) = mo;

        //std::cerr << "EE\n";
    }

    for (int i = 0; i < map_size; i++)
    {
        //std::cerr << "FF\n";
        for (int j = 0; j < map_size; j++)
        {
            //std::cerr << "GG\n";
            terrain_type[i].at(j) = 0;
            tree_type[i].at(j) = 255;
            building_type[i].at(j) = 0;
            map_objects[i].at(j) = NULL;
        }
    }

    //tree_type[0][0] = 0;
    tree_type[map_size-1][0] = 0;
    //tree_type[0][MAP_SIZE-1] = 0;
    //tree_type[1][MAP_SIZE-1] = 0;
    //tree_type[2][MAP_SIZE-1] = 0;
    //tree_type[2][1] = 0;
    //tree_type[1][1] = 0;

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

MapObject* TerrainMap::get_map_object(int x, int y){
    return map_objects[x][y];
}

int TerrainMap::coord_to_virtual_bitmap_x(int x, int y){
    // tile_offset = (x-y)
    // center line = MAP_SIZE/2
    return map_size/2*60-(((map_size/2)-(x-y))*-60)-60;
}

int TerrainMap::coord_to_virtual_bitmap_y(int x, int y){
    return x*20 + y*20;
}

int TerrainMap::virtual_bitmap_to_coord_y(int x, int y){
    int r =  (int) ((x/3.0) - 20*map_size + y)/40.0;
    if (r < 0) {
        return 0;
    }
    if (r >= map_size) {
        return map_size - 1;
    }
    return r;
}

int TerrainMap::virtual_bitmap_to_coord_x(int x, int y){
    int r = (int) ((x/3.0) - 20*map_size -y)/-40.0;
    if (r < 0) {
        return 0;
    }
    if (r >= map_size) {
        return map_size - 1;
    }
    return r;
}

int TerrainMap::get_map_size()
{
    return map_size;
}

void TerrainMap::plant_tree(int coord_x, int coord_y)
{
    if ( coord_x >= 0 && coord_y >= 0 && coord_x < map_size && coord_y < map_size)
    {
        tree_type[coord_x][coord_y] = 0;
    }
}

void TerrainMap::remove_tree(int coord_x, int coord_y)
{
    if ( coord_x >= 0 && coord_y >= 0 && coord_x < map_size && coord_y < map_size)
    {
        tree_type[coord_x][coord_y] = 255;
    }
}
