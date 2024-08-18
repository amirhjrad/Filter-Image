#ifndef EFFECTS_H
#define EFFECTS_H
#include <iostream>
#include <string>
#include <vector>
#include "bmp.hpp"
#include "get_instr.h"
#include "get_images.h"
#include "kernels.h"
#include "adds.h"
#include "consts.h"

class Effects
{
protected:
    std::vector<std::string> filters;  
    std::vector<std::string> views;  
    std::vector<std::string> inputs_adr;
    std::vector<std::string> outputs_adr;
    std::vector<Bmp> images;
    std::vector<Krnl> kernels;
    int viewX, viewY, viewWidth, viewHeight;
    int kernel[3][3], kernelSum;
    void setKernel(int kernId);
    void setView(int i ,Bmp currBmp);
    void updatePixels(int sumR, int sumG, int sumB, int ii,int i, int j);
    void updatePixelsInvert(int i, int j, int ii);
    void updatePixelsGray(int i, int j, int ii);
    void setRowCol(int pixelRow, int pixelCol, Bmp& bmp, int& row, int& col, int i, int j);
    void saveOutput();
public:
    void init(GetInstr& instr, GetImage& imagesBmp);
    void setBlur(int viewIndex);
    void setSharpen(int viewIndex);
    void setEmboss(int viewIndex);
    void setInvert(int viewIndex);
    void setGray(int viewIndex);
};


#endif