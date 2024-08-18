#include "adds.h"

std::vector<std::string> separateText(std::string text, char seperator)
{
    std::vector<std::string> result;
    std::string token;
    int start = 0;
    int end = text.find(seperator);
    while (end != -1) {
        token = text.substr(start, end - start);
        result.push_back(token);
        start = end + 1;
        end = text.find(seperator, start);
    }
    token = text.substr(start, end);
    result.push_back(token);
    return result;
}