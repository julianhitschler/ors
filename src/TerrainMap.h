#ifndef TERRAIN_MAP_H
#define TERRAIN_MAP_H

#include <vector>
#include <iostream>
#include "MapObject.h"
#include "Tree.h"
#include <random>
#include "MapObjectTypeRecord.h"

class TerrainMap
{
    public:
        TerrainMap();
        virtual ~TerrainMap();
        int get_terrain_type(int x, int y);
        int get_tree_type(int x, int y);
        int get_display_object(int x, int y);
        MapObject* get_map_object(int x, int y);
        void set_terrain_type(int x, int y, int value);
        void set_tree_type(int x, int y, int value);
        void set_display_object(int x, int y, int value);
        void set_map_object(int x, int y, MapObject* value);
        int get_map_size();
        void place_object(int coord_x, int coord_y, MapObjectTypeRecord* motr, MapObject *mo);
        void remove_object(int coord_x, int coord_y);
        void plant_tree(int coord_x, int coord_y, TreeTypeRecord* tt);
        void remove_tree(int coord_x, int coord_y);
        int coord_to_virtual_bitmap_x(int x, int y);
        int coord_to_virtual_bitmap_y(int x, int y);
        int virtual_bitmap_to_coord_x(int x, int y);
        int virtual_bitmap_to_coord_y(int x, int y);
    protected:
    private:
        int map_size;
        std::vector<std::vector<unsigned short> > terrain_type;
        std::vector<std::vector<unsigned short> > tree_type;
        //Semantics: 255 is free, others are free families
        std::vector<std::vector<unsigned short> > display_object;
        std::vector<std::vector<MapObject*> > map_objects;
        //Semantics: 0: free, 1: user building, 2: destructable building 3: other building
};

#endif //TERRAIN_MAP_H
