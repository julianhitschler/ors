#include "TreeTypeRecord.h"
#include "Tree.h"

Tree::Tree()
{
    wood = 100;
    tree_type = new TreeTypeRecord();
    //ctor
}

Tree::~Tree()
{
    //dtor
    delete &tree_type;
}
