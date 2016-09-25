#ifndef TERRAIN_MAP_H
#define TERRAIN_MAP_H

const int MAP_SIZE = 8;

class TerrainMap
{
    public:
        TerrainMap();
        virtual ~TerrainMap();
        int get_terrain_type(int x, int y);
        int get_tree_type(int x, int y);
        int get_building_type(int x, int y);

        int coord_to_virtual_bitmap_x(int x, int y);
        int coord_to_virtual_bitmap_y(int x, int y);

    protected:
    private:
        unsigned short terrain_type [MAP_SIZE][MAP_SIZE];
        unsigned short tree_type [MAP_SIZE][MAP_SIZE];
        //Semantics: 255 is free, others are free families
        unsigned short building_type [MAP_SIZE][MAP_SIZE];
        //Semantics: 0: free, 1: user building, 2: destructable building 3: other building
};

#endif //TERRAIN_MAP_H
