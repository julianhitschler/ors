#ifndef TERRAIN_MAP_H
#define TERRAIN_MAP_H

#include <vector>

class TerrainMap
{
    public:
        TerrainMap();
        virtual ~TerrainMap();
        int get_terrain_type(int x, int y);
        int get_tree_type(int x, int y);
        int get_building_type(int x, int y);
        int get_map_size();
        void plant_tree(int coord_x, int coord_y);
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
        std::vector<std::vector<unsigned short> > building_type;
        //Semantics: 0: free, 1: user building, 2: destructable building 3: other building

};

#endif //TERRAIN_MAP_H
