#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include "GameState.h"
#include <iostream>
#include <fstream>

class ConfigParser
{
    public:
        ConfigParser();
        virtual ~ConfigParser();
        void parseConfig(std::string file_name, GameState* gs);
    protected:
    private:
};

#endif // CONFIGPARSER_H
