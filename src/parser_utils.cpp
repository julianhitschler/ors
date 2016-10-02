#include "parser_utils.h"

std::map<std::string,std::string>* parseFile(std::string file_name){

    std::map<std::string,std::string>* parse_map = new std::map<std::string,std::string>();

    std::string line;
    std::ifstream file;
    std::vector<std::string> elements;
    std::vector<std::string> inner_elements;
    file.open(file_name);
    int n = 0;
    while (getline(file, line))
    {
        if (line[0] == '#')
        {
            continue;
        }
        elements = split(line, ":", false);
        if (elements.size() < 2)
        {
            std::cerr << "Formatting error in line "<<n<<":" << line;
            exit(10);
        } else {
            parse_map->insert(std::pair<std::string,std::string>("ID",elements[0]));
            elements = split(elements[1], ";", false);
            for(std::string s: elements)
            {
                std::cout << s << ",";
                inner_elements = split(s, "=", false);
                if (s[s.length()-1] == '\n')
                {
                    s = s.erase(s.length()-2, s.length()-1);
                }
                if (inner_elements.size() != 2)
                {
                    std::cerr << "Formatting error in line "<<n<<":" << line;
                    std::cerr << "Offending element:" << s << std::endl;
                    exit(11);
                } else {
                    parse_map->insert(std::pair<std::string,std::string>(inner_elements[0],inner_elements[1]));
                }

            }
        }
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
