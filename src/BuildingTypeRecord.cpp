#include "BuildingTypeRecord.h"

BuildingTypeRecord::BuildingTypeRecord()
{
    //ctor
    tear_down_cost = 0;
}

BuildingTypeRecord::~BuildingTypeRecord()
{
    //dtor
}

int BuildingTypeRecord::get_tear_down_cost()
{
    return tear_down_cost;
}

void BuildingTypeRecord::set_tear_down_cost(int i)
{
    tear_down_cost = i;
}
