#ifndef CONSTS_H
#define CONSTS_H
#include <iostream>

const char VIEW_SEPARATOR = ':';
const char IO_ADR_SEPARATOR = ' ';
const char FILTERS_SIGN = '-';
const std::string BLUR_FILTER = "B";
const std::string SHARPEN_FILTER = "S";
const std::string EMBOSS_FILTER = "E";
const std::string GRAY_FILTER = "G";
const std::string INVERT_FILTER = "I";
const std::string NOT_A_VIEW = "NaV";
const int BLUR_KERNEL_ID = 0;
const int SHARPEN_KERNEL_ID = 1;
const int EMBOSS_KERNEL_ID = 2;

#endif