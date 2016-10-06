#include "MapObject.h"

MapObject::MapObject()
{
    //ctor
    x_coord = 0;
    y_coord = 0;
    graphics_record = NULL;
    map_object_type_record = NULL;
}

MapObject::~MapObject()
{
    //dtor
    delete &graphics_record;
}

int MapObject::get_coord_x()
{
    return x_coord;
}

int MapObject::get_coord_y()
{
    return y_coord;
}

void MapObject::set_coord_x(int x)
{
    x_coord = x;
}

void MapObject::set_coord_y(int y)
{
    y_coord = y;
}

GraphicsRecord* MapObject::get_graphics_record()
{
    return graphics_record;
}

void MapObject::set_graphics_record(GraphicsRecord* gr)
{
    graphics_record = gr;
}

MapObjectTypeRecord* MapObject::get_type_record()
{
    return map_object_type_record;
}

void MapObject::set_type_record(MapObjectTypeRecord* motr)
{
    map_object_type_record = motr;
}

