#include "GraphicsRecord.h"

GraphicsRecord::GraphicsRecord()
{
    //ctor
    graphics = new std::vector<SDL_Surface*>(10, NULL);
    graphics_files = new std::vector<std::string>(10, "");
}

GraphicsRecord::~GraphicsRecord()
{
    //dtor
    delete &graphics;
    delete &graphics_files;
}

void GraphicsRecord::set_graphics_file_name(std::string file_name, int position)
{
    if (graphics_files->size() <= position){
        graphics_files->reserve(position+10);
    }
    graphics_files->at(position) = file_name;
}

std::string* GraphicsRecord::get_graphics_file_name( int position )
{
    if (graphics_files->size() <= position){
        return NULL;
    }
    return &graphics_files->at(position);
}

void GraphicsRecord::set_graphics(SDL_Surface* surface, int position)
{
    if (graphics->size() <= position){
        graphics->reserve(position+10);
    }
    graphics->at(position) = surface;
}

SDL_Surface* GraphicsRecord::get_graphics( int position )
{
    if (graphics->size() <= position){
        std::cerr << "Q\n";
        return NULL;
    }
    return graphics->at(position);
}
