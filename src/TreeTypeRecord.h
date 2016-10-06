#ifndef TREETYPERECORD_H
#define TREETYPERECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"
#include "GraphicsRecord.h"
#include "MapObjectTypeRecord.h"

class TreeTypeRecord: public  MapObjectTypeRecord
{
    public:
        TreeTypeRecord();
        virtual ~TreeTypeRecord();
        int get_wood_initial();
        void set_wood_initial(int i);
    protected:
    private:
        int wood_initial;
};

#endif // TREETYPERECORD_H
