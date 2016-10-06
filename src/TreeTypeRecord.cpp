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

void TreeTypeRecord::set_wood_initial(int i)
{
    wood_initial = i;
}

int TreeTypeRecord::get_wood_initial()
{
    return wood_initial;
}
