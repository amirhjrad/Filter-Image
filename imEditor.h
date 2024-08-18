#ifndef IMEDITOR_H
#define IMEDITOR_H
#include <iostream>
#include <vector>
#include "get_instr.h"
#include "get_images.h"
#include "bmp.hpp"
#include "effects.h"
#include "consts.h"



class ImEditor : public Effects
{
private:
    void applyEffect();
public:
    ImEditor(GetInstr& instr, GetImage& imagesBmp);
};





#endif