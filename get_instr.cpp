#include "get_instr.h"

GetInstr::GetInstr(int argc, char* argv[]) 
{
    //-G 32:40:200:200 -B -B -B -I 233:40:200:100 -I 400:400:100:209
    filters = {"G","B","B","B","I","I"};
    views = {"32:40:200:200","NaV","Nav","Nav","233:40:200:100","400:400:100:209"};
    // for (int i = 1; i < argc; i++) 
    // {
    //     std::string arg = argv[i];
    //     if (arg[0] == FILTERS_SIGN) 
    //     {
    //         std::string filter = arg.substr(1);
    //         filters.push_back(filter);
    //         views.push_back(NOT_A_VIEW);
    //     } 
    //     else views[i/2-1] = arg;
    // }
}

std::vector<std::string> GetInstr::getFilters() { return filters; }

std::vector<std::string> GetInstr::getViews() { return views; }