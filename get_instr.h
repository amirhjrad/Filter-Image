#ifndef INST_H
#define INST_H
#include <iostream>
#include <string>
#include <vector>
#include "consts.h"

class GetInstr {
private:
    std::vector<std::string> filters;
    std::vector<std::string> views;
public:
    GetInstr(int argc, char* argv[]);
    std::vector<std::string> getFilters();
    std::vector<std::string> getViews();
};

#endif  