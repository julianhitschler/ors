#include "ConfigParser.h"

ConfigParser::ConfigParser()
{
    game_state = NULL;
    //ctor
}

ConfigParser::~ConfigParser()
{
    //dtor
}

void ConfigParser::parseConfig(std::string file_name, GameState* gs)
{
    game_state = gs;
    std::string s;
    std::vector<std::map<std::string,std::string>* > parseMaps = parseFile(file_name);
    for(std::map<std::string,std::string>* parseMap : parseMaps)
    {
        s = parseMap->at(std::string("ELEMENT_NAME"));
        if ( s == "TREE_TYPE")
        {
            parseTreeType(parseMap);
        }
    }
}

void ConfigParser::parseTreeType(std::map<std::string,std::string>* parseMap)
{
    TreeTypeRecord *tt = new TreeTypeRecord();
    game_state->add_tree_type(tt, 0);
}


