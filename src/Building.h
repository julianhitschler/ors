#ifndef BUILDING_H
#define BUILDING_H

#include "BuildingTypeRecord.h"

class Building
{
    public:
        Building(BuildingTypeRecord* bt);
        virtual ~Building();
    protected:
    private:
        BuildingTypeRecord *building_type_record;
};

#endif // BUILDING_H
