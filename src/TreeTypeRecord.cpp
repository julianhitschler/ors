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
