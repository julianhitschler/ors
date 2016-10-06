#include "MapObject.h"

MapObject::MapObject()
{
    //ctor
    x_coord = 0;
    y_coord = 0;
    map_object_type_record = NULL;
}

MapObject::~MapObject()
{
    //dtor
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

MapObjectTypeRecord* MapObject::get_type_record()
{
    return map_object_type_record;
}

void MapObject::set_type_record(MapObjectTypeRecord* motr)
{
    map_object_type_record = motr;
}

