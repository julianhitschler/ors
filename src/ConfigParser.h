#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include "GameState.h"
#include <iostream>
#include <fstream>
#include "parser_utils.h"
#include <map>
#include "MapObjectTypeRecord.h"
#include "TreeTypeRecord.h"
#include "GraphicsRecord.h"

class ConfigParser
{
    public:
        ConfigParser();
        virtual ~ConfigParser();
        void parseConfig(std::string file_name, GameState* gs);
        void parseTreeType(std::map<std::string,std::string>* parseMap);
        GraphicsRecord* parseGraphics(std::map<std::string,std::string>* parseMap);
        void parseMapObject(std::map<std::string,std::string>* parseMap, MapObjectTypeRecord *motr);
    protected:
    private:
        GameState *game_state;
};

#endif // CONFIGPARSER_H
