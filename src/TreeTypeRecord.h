#ifndef TREETYPERECORD_H
#define TREETYPERECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"
#include "GraphicsRecord.h"

class TreeTypeRecord
{
    public:
        TreeTypeRecord();
        virtual ~TreeTypeRecord();
        int get_wood_initial();
        void set_type_index(int i);
        void set_wood_initial(int i);
        void set_graphics_record(GraphicsRecord *gr);
        GraphicsRecord* get_graphics_record();
    protected:
    private:
        int type_index;
        int wood_initial;
        std::vector<int> graphics_start_month;
        GraphicsRecord *graphics_record;
};

#endif // TREETYPERECORD_H
