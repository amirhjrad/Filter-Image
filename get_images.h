#ifndef GET_IMAGES_H
#define GET_IMAGES_H
#include <iostream>
#include <string>
#include <vector>
#include "bmp.hpp"
#include "adds.h"
#include "consts.h"


class GetImage
{
private:
    std::vector<std::string> inputsAdr;
    std::vector<std::string> outputsAdr;
    std::vector<Bmp> images;
    void readImages(std::vector<std::string> inputsAdr);
    
public:
    GetImage();
    std::vector<std::string> getInputs();
    std::vector<std::string> getOutputs();    
    std::vector<Bmp> getImages();    
};



#endif