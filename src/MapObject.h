#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "SDL/SDL.h"
#include <vector>
#include <string>
#include "GraphicsRecord.h"

class MapObject
{
    public:
        MapObject();
        virtual ~MapObject();
        int get_coord_x();
        int get_coord_y();
        int get_offset_x();
        int get_offset_y();
        int get_size_x();
        int get_size_y();
        void set_coord_x(int x);
        void set_coord_y(int y);
        void set_offset_x(int x);
        void set_offset_y(int y);
        void set_size_x(int x);
        void set_size_y(int y);
        GraphicsRecord* get_graphics_record();
        void set_graphics_record(GraphicsRecord *gr);
    protected:
    private:
        int x_coord;
        int y_coord;
        int offset_x;
        int offset_y;
        int size_x;
        int size_y;
        GraphicsRecord *graphics_record;

};

#endif // MAPOBJECT_H
