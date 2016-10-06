#ifndef BUILDINGTYPERECORD_H
#define BUILDINGTYPERECORD_H

#include "MapObjectTypeRecord.h"

class BuildingTypeRecord: public MapObjectTypeRecord
{
    public:
        BuildingTypeRecord();
        virtual ~BuildingTypeRecord();
        int get_tear_down_cost();
        void set_tear_down_cost(int i);
    protected:
    private:
        int tear_down_cost;
};

#endif // BUILDINGTYPERECORD_H
