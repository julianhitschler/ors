#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "SDL/SDL.h"
#include <vector>
#include <string>
#include "GraphicsRecord.h"
#include "MapObjectTypeRecord.h"

class MapObject
{
    public:
        MapObject();
        virtual ~MapObject();
        int get_coord_x();
        int get_coord_y();
        void set_coord_x(int x);
        void set_coord_y(int y);
        MapObjectTypeRecord* get_type_record();
        void set_type_record(MapObjectTypeRecord *motr);
        GraphicsRecord* get_graphics_record();
        void set_graphics_record(GraphicsRecord *gr);
    protected:
    private:
        int x_coord;
        int y_coord;
        GraphicsRecord *graphics_record;
        MapObjectTypeRecord *map_object_type_record;

};

#endif // MAPOBJECT_H
