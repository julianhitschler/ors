#include "MapObject.h"

MapObject::MapObject()
{
    //ctor
    x_coord = 0;
    y_coord = 0;
    offset_x = 0;
    offset_y = 0;
    size_x = 0;
    size_y = 0;
    graphics_record = NULL;
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
int MapObject::get_offset_x()
{
    return offset_x;
}

int MapObject::get_offset_y()
{
    return offset_y;
}

int MapObject::get_size_x()
{
    return size_x;
}

int MapObject::get_size_y()
{
    return size_y;
}

void MapObject::set_coord_x(int x)
{
    x_coord = x;
}

void MapObject::set_coord_y(int y)
{
    y_coord = y;
}

void MapObject::set_offset_x(int x)
{
    offset_x = x;
}

void MapObject::set_offset_y(int y)
{
    offset_y = y;
}

void MapObject::set_size_x(int x)
{
    size_x = x;
}

void MapObject::set_size_y(int y)
{
    size_y = y;
}

GraphicsRecord* MapObject::get_graphics_record()
{
    return graphics_record;
}

void MapObject::set_graphics_record(GraphicsRecord* gr)
{
    graphics_record = gr;
}
