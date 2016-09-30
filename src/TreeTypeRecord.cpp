#include "TreeTypeRecord.h"
#include <string>
#include <vector>

TreeTypeRecord::TreeTypeRecord()
{
    //ctor
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

