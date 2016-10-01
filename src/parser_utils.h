#include "parser_utils.h"

std::map<std::string,std::string>* parseFile(std::string file_name){

    std::map<std::string,std::string>* parse_map = new std::map<std::string,std::string>();

    std::string line;
    ifstream file;
    file.open(file_name);
    while (getline(file, line))
    {
        std::cout << line;
    }
    file.close();
    return parse_map;
}
