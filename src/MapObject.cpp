#include "MapObject.h"

MapObject::MapObject()
{
    //ctor
    x_coord = 0;
    y_coord = 0;
    graphics_record = new GraphicsRecord();
}

MapObject::~MapObject()
{
    //dtor
    delete &graphics_record;
}
