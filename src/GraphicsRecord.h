#ifndef GRAPHICSRECORD_H
#define GRAPHICSRECORD_H

#include <string>
#include <vector>
#include "SDL/SDL.h"

class GraphicsRecord
{
    public:
        GraphicsRecord();
        virtual ~GraphicsRecord();
        void set_graphics_file(std::string file_name, int position);
    protected:
    private:
        std::vector<SDL_Surface> *graphics;
        std::vector<std::string> *graphics_files;
};

#endif // GRAPHICSRECORD_H
