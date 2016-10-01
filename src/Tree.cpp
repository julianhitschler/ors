#include "TreeTypeRecord.h"
#include "Tree.h"

Tree::Tree(TreeTypeRecord* tr)
{
    tree_type = tr;
    wood = tree_type->get_wood_initial();
    this->set_offset_x(tree_type->get_offset_x());
    this->set_offset_y(tree_type->get_offset_y());
    this->set_graphics_record(tree_type->get_graphics_record());
    //ctor
}

Tree::~Tree()
{
    //dtor
}
