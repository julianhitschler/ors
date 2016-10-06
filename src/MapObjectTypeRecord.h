#ifndef MAPOBJECTTYPERECORD_H
#define MAPOBJECTTYPERECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"
#include "GraphicsRecord.h"

class MapObjectTypeRecord
{
    public:
        MapObjectTypeRecord();
        virtual ~MapObjectTypeRecord();
        int get_id();
        int get_offset_x();
        int get_offset_y();
        void set_type_index(int i);
        void set_offset_x(int i);
        void set_offset_y(int i);
        void set_graphics_record(GraphicsRecord *gr);
        GraphicsRecord* get_graphics_record();
        void set_id(int i);
    protected:
    private:
        int id;
        int offset_x;
        int offset_y;
        int type_index;
        std::vector<int> graphics_start_month;
        GraphicsRecord *graphics_record;
};

#endif // MAPOBJECTTYPERECORD_H
