#include "TreeTypeRecord.h"

TreeTypeRecord::TreeTypeRecord()
{
    //ctor
    wood_initial = 40;
}

TreeTypeRecord::~TreeTypeRecord()
{
    //dtor
}

void TreeTypeRecord::set_type_index(int i)
{
    type_index = i;
}

void TreeTypeRecord::set_wood_initial(int i)
{
    wood_initial = i;
}

void TreeTypeRecord::set_graphics_record(GraphicsRecord *gr)
{
    graphics_record = gr;
}

GraphicsRecord* TreeTypeRecord::get_graphics_record()
{
    return graphics_record;
}

int TreeTypeRecord::get_wood_initial()
{
    return wood_initial;
}

int TreeTypeRecord::get_offset_x()
{
    return offset_x;
}

int TreeTypeRecord::get_offset_y()
{
    return offset_y;
}

void TreeTypeRecord::set_offset_x(int i)
{
    offset_x = i;
}

void TreeTypeRecord::set_offset_y(int i)
{
    offset_y = i;
}
