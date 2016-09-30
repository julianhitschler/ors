#ifndef TREE_H
#define TREE_H

#include "MapObject.h"
#include "GraphicsRecord.h"

class Tree: public MapObject
{
    public:
        Tree();
        virtual ~Tree();
    protected:
    private:
        int wood;
        TreeTypeRecord *tree_type;
};

#endif // TREE_H
