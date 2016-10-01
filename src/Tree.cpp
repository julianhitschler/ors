#include "TreeTypeRecord.h"
#include "Tree.h"

Tree::Tree(TreeTypeRecord* tr)
{
    std::cerr << "G\n";
    tree_type = tr;
    std::cerr << "H\n";
    wood = tree_type->get_wood_initial();
    this->set_offset_x(tree_type->get_offset_x());
    this->set_offset_y(tree_type->get_offset_y());
    std::cerr << "E\n";
    this->set_graphics_record(tree_type->get_graphics_record());
    std::cerr << "F\n";
    //ctor
}

Tree::~Tree()
{
    //dtor
}
