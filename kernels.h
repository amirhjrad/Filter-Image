#ifndef KERNELS_H
#define KERNELS_H

typedef std::vector<std::vector<int>> Krnl;

const Krnl BLUR_KERNEL = {
            {1, 2, 1},
            {2, 4, 2},
            {1, 2, 1}
        };

const Krnl SHARPEN_KERNEL = {
            {0, -1, 0},
            {-1, 5, -1},
            {0, -1, 0}
        };

const Krnl EMBOSS_KERNEL = {
            {-2, -1, 0},
            {-1, 1, 1},
            {0, 1, 2}
        };
        
#endif