#ifndef TREE_H
#define TREE_H

class Tree
{
    public:
        Tree();
        virtual ~Tree();
    protected:
    private:
        int x_position;
        int y_position;
        int wood;
        TreeTypeRecord tree_type;
};

#endif // TREE_H
