#include "parser_utils.h"

std::vector<std::map<std::string,std::string>* > parseFile(std::string file_name)
{



    std::vector<std::map<std::string,std::string>* > parse_map_vector;
    std::map<std::string,std::string>* parse_map;

    std::string line;
    std::string value;
    std::ifstream file;
    std::vector<std::string> elements;
    std::vector<std::string> middle_elements;
    std::vector<std::string> inner_elements;
    file.open(file_name.c_str());
    int n = 0;
    while (getline(file, line))
    {
        if (line[0] == '#')
        {
            continue;
        }
        if (line[0] == '\n')
        {
            continue;
        }
        parse_map = new std::map<std::string,std::string>();
        elements = split(line, ":", false);
        if (elements.size() < 2)
        {
            std::cerr << "Formatting error in line "<<n<<":" << line;
            exit(10);
        } else {
            parse_map->insert(std::pair<std::string,std::string>("ELEMENT_NAME",elements[0]));
            middle_elements = split(elements[1], ",", false);
            for(std::string s: middle_elements)
            {
                //std::cout << s << ",";
                inner_elements = split(s, "=", false);
                if (s[s.length()-1] == '\n')
                {
                    s = s.erase(s.length()-2, s.length()-1);
                }
                if (inner_elements.size() != 2)
                {
                    std::cerr << "Formatting error in line "<<n<<":" << line << std::endl;
                    std::cerr << "Offending element:" << s << std::endl;
                    exit(11);
                } else {
                    value = inner_elements[1];
                    if (value[0] == '"')
                    {
                        value = value.substr(1,value.length()-2);
                    }
                    parse_map->insert(std::pair<std::string,std::string>(inner_elements[0],value));
                }

            }
            parse_map_vector.push_back(parse_map);
            n++;
        }
    }
    file.close();
    return parse_map_vector;
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
