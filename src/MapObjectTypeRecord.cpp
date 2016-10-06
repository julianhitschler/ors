#include "MapObjectTypeRecord.h"

MapObjectTypeRecord::MapObjectTypeRecord()
{
    //ctor
    extent_x = 1;
    extent_y = 1;
}

MapObjectTypeRecord::~MapObjectTypeRecord()
{
    //dtor
}

void MapObjectTypeRecord::set_type_index(int i)
{
    type_index = i;
}

void MapObjectTypeRecord::set_graphics_record(GraphicsRecord *gr)
{
    graphics_record = gr;
}

GraphicsRecord* MapObjectTypeRecord::get_graphics_record()
{
    return graphics_record;
}

int MapObjectTypeRecord::get_offset_x()
{
    return offset_x;
}

int MapObjectTypeRecord::get_offset_y()
{
    return offset_y;
}

void MapObjectTypeRecord::set_offset_x(int i)
{
    offset_x = i;
}

void MapObjectTypeRecord::set_offset_y(int i)
{
    offset_y = i;
}

int MapObjectTypeRecord::get_id()
{
    return id;
}

void MapObjectTypeRecord::set_id(int i)
{
    id = i;
}

int MapObjectTypeRecord::get_extent_x()
{
    return extent_x;
}

int MapObjectTypeRecord::get_extent_y()
{
    return extent_y;
}

void MapObjectTypeRecord::set_extent_x(int i)
{
    extent_x = i;
}

void MapObjectTypeRecord::set_extent_y(int i)
{
    extent_y = i;
}
