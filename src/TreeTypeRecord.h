#ifndef TREETYPERECORD_H
#define TREETYPERECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"
#include "GraphicsRecord.h"

class TreeTypeRecord: public GraphicsRecord
{
    public:
        TreeTypeRecord();
        virtual ~TreeTypeRecord();
        void set_type_index(int i);
        void set_wood_initial(int i);
    protected:
    private:
        int type_index;
        int wood_initial;
        std::vector<int> graphics_start_month;
};

#endif // TREETYPERECORD_H
