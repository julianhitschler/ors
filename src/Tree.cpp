#include "Tree.h"

Tree::Tree(TreeTypeRecord* tr)
{
    tree_type = tr;
    this->set_type_record(tr);
    wood = tree_type->get_wood_initial();
    this->set_graphics_record(tree_type->get_graphics_record());
    //ctor
}

Tree::~Tree()
{
    //dtor
}
