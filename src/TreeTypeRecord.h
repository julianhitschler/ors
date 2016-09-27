#ifndef TREETYPERECORD_H
#define TREETYPERECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"

class TreeTypeRecord
{
    public:
        TreeTypeRecord();
        virtual ~TreeTypeRecord();
        void set_type_index(int i);
        void set_wood_initial(int i);
    protected:
    private:
        int type_index;
        int wood_initial;
        std::vector<std::string> graphics_files;
        std::vector<int> graphics_start_month;
        std::vector<SDL_Surface> graphics;
};

#endif // TREETYPERECORD_H