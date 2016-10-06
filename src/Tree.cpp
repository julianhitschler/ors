#include "Tree.h"

Tree::Tree(TreeTypeRecord* tr)
{
    tree_type = tr;
    this->set_type_record(tr);
    wood = tree_type->get_wood_initial();
    //ctor
}

Tree::~Tree()
{
    //dtor
}
