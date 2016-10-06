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
    protected:
    private:
        int x_coord;
        int y_coord;
        MapObjectTypeRecord *map_object_type_record;

};

#endif // MAPOBJECT_H
