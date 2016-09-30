#ifndef TREE_H
#define TREE_H

#include "MapObject.h"
#include "GraphicsRecord.h"
#include "TreeTypeRecord.h"
#include <iostream>

class Tree: public MapObject
{
    public:
        Tree(TreeTypeRecord* tr);
        virtual ~Tree();
    protected:
    private:
        int wood;
        TreeTypeRecord *tree_type;
};

#endif // TREE_H
