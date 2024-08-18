#include "get_images.h"

GetImage::GetImage()
{   
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line == ".")
            break;
        std::vector<std::string> tmp = separateText(line,IO_ADR_SEPARATOR);
        inputsAdr.push_back(tmp[0]);
        outputsAdr.push_back(tmp[1]);
    }
    readImages(inputsAdr);
}

void GetImage::readImages(std::vector<std::string> inputsAdr)
{
    for (int i = 0; i < static_cast<int>(inputsAdr.size()); i++)
    {
        Bmp tmpBmp;
        read(tmpBmp, inputsAdr[i]);
        images.push_back(tmpBmp);
    }
    
}

std::vector<std::string> GetImage::getInputs() { return inputsAdr; }

std::vector<std::string> GetImage::getOutputs() { return outputsAdr; }

std::vector<Bmp> GetImage::getImages() { return images; }
