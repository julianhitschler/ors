#ifndef PARSER_UTILS_H
#define PARSER_UTILS_H

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::map<std::string,std::string>* parseFile(std::string file_name);
std::vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty);

#endif //PARSER_UTILS_H
