#include "GraphicsRecord.h"

GraphicsRecord::GraphicsRecord()
{
    //ctor
    graphics = new std::vector<SDL_Surface>(10);
    graphics_files = new std::vector<std::string>(10);
}

GraphicsRecord::~GraphicsRecord()
{
    //dtor
    delete &graphics;
    delete &graphics_files;
}

void GraphicsRecord::set_graphics_file(std::string file_name, int position)
{
    if (graphics_files->size() <= position){
        graphics_files->reserve(position+141);
    }
    graphics_files->at(position) = file_name;
}
