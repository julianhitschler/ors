#ifndef TERRAIN_MAP_H
#define TERRAIN_MAP_H

const int MAP_SIZE = 4096;

class TerrainMap
{
    public:
        TerrainMap();
        virtual ~TerrainMap();
        int get_terrain_type(int x, int y);
        int get_tree_type(int x, int y);
        int get_building_type(int x, int y);
    protected:
    private:
        unsigned short terrain_type [MAP_SIZE][MAP_SIZE];
        unsigned short tree_type [MAP_SIZE][MAP_SIZE];
        unsigned short building_type [MAP_SIZE][MAP_SIZE];
};

#endif //TERRAIN_MAP_H
