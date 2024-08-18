#include <iostream>
#include "get_instr.h"
#include "get_images.h"
#include "imEditor.h"
#include "effects.h"



int main(int argc, char* argv[]) {
    GetInstr instr(argc, argv); 
    GetImage images;
    ImEditor imageEditor(instr, images);
    return 0;
}