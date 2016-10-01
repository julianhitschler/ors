#include "parser_utils.h"

std::map<std::string,std::string>* parseFile(std::string file_name){

    std::map<std::string,std::string>* parse_map = new std::map<std::string,std::string>();

    std::string line;
    std::ifstream file;
    file.open(file_name);
    while (getline(file, line))
    {
        std::cout << line;
    }
    file.close();
    return parse_map;
}

//Standard string splitting function copied from here: http://stackoverflow.com/questions/236129/split-a-string-in-c

std::vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty = false) {
    std::vector<std::string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    std::string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        std::string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}
