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
    protected:
    private:
        int x_coord;
        int y_coord;
        GraphicsRecord *graphics_record;
};

#endif // MAPOBJECT_H
