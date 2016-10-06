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
    std::cout << "Parsing file:" << file_name << std::endl;
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
    std::cout << "Done Parsing!" << std::endl;
}

void ConfigParser::parseTreeType(std::map<std::string,std::string>* parseMap)
{
    TreeTypeRecord *tt = new TreeTypeRecord();
    parseMapObject(parseMap, tt);
    tt->set_wood_initial(std::stoi(parseMap->at("wood")));
    game_state->add_tree_type(tt, std::stoi(parseMap->at("id")));
}

void ConfigParser::parseMapObject(std::map<std::string, std::string>* parseMap, MapObjectTypeRecord *motr)
{
    motr->set_id(std::stoi(parseMap->at("id")));
    motr->set_graphics_record(parseGraphics(parseMap));
    motr->set_offset_x(std::stoi(parseMap->at("offset_x")));
    motr->set_offset_y(std::stoi(parseMap->at("offset_y")));
    motr->set_extent_x(std::stoi(parseMap->at("size_x")));
    motr->set_extent_y(std::stoi(parseMap->at("size_y")));
}

GraphicsRecord* ConfigParser::parseGraphics(std::map<std::string,std::string>* parseMap)
{
    GraphicsRecord *graphics_record = new GraphicsRecord();
    graphics_record->set_graphics_file_name(parseMap->at("gfx_0"), 0);
    //std::cout << parseMap->at("gfx_0");
    return graphics_record;
}
