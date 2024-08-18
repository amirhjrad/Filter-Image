#include "imEditor.h"

ImEditor::ImEditor(GetInstr& instr, GetImage& imagesBmp)
{
    init(instr, imagesBmp);
    applyEffect();
}

void ImEditor::applyEffect()
{
    for (int i = 0; i < static_cast<int>(filters.size()); i++)
    {
        if (filters[i] == BLUR_FILTER)
            setBlur(i);
        else if(filters[i] == SHARPEN_FILTER)
            setSharpen(i);
        else if(filters[i] == EMBOSS_FILTER)
            setEmboss(i);
        else if(filters[i] == INVERT_FILTER)
            setInvert(i);
        else if(filters[i] == GRAY_FILTER)
            setGray(i);
    }
}

