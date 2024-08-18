#include "effects.h"

void Effects::init(GetInstr& instr, GetImage& imagesBmp)
{
    filters = instr.getFilters();  
    views = instr.getViews();  
    inputs_adr = imagesBmp.getInputs();
    outputs_adr = imagesBmp.getOutputs();
    for (int i = 0; i < static_cast<int>(imagesBmp.getImages().size()); i++)
    {
        std::vector<Bmp> tmpImage = imagesBmp.getImages();
        images.push_back(tmpImage[i]);
    }
    kernels.push_back(BLUR_KERNEL);
    kernels.push_back(SHARPEN_KERNEL);
    kernels.push_back(EMBOSS_KERNEL);
}

void Effects::setKernel(int kernId)
{
    kernelSum = 0;
    for (int i = 0; i < static_cast<int>(kernels[kernId].size()); i++) {
        for (int j = 0; j < static_cast<int>(kernels[kernId][i].size()); j++) {
            kernel[i][j] = kernels[kernId][i][j];
            kernelSum += kernels[kernId][i][j];
        }
    }
}

void Effects::setView(int i, Bmp currBmp)
{
    bool a = views[i] == "Nav";
    if (views[i] == "Nav")
    {
        viewX = 0;
        viewY = 0;
        viewWidth = currBmp.infoHdr.width;
        viewHeight = currBmp.infoHdr.height;
    }
    else 
    {
        std::vector<std::string> data = separateText(views[i],VIEW_SEPARATOR);
        viewX = std::stoi(data[0]);
        viewY = std::stoi(data[1]);
        viewWidth = std::stoi(data[2]);
        viewHeight = std::stoi(data[3]);
    }
}

void Effects::updatePixels(int sumR, int sumG, int sumB, int ii,int i, int j)
{
    int R = sumR / kernelSum;
    int G = sumG / kernelSum;
    int B = sumB / kernelSum;
    if (R > 255) R = 255;
    else if (R < 0) R = 0;
    if (G > 255) G = 255;
    else if (G < 0) G = 0;
    if (B > 255) B = 255;
    else if (B < 0) B = 0;
    images[ii].data[i][j] = Pixel(R, G, B);
}

void Effects::updatePixelsInvert(int i, int j, int ii)
{
    int R = images[ii].data[i][j].red;
    int G = images[ii].data[i][j].grn;
    int B = images[ii].data[i][j].blu;
    images[ii].data[i][j] = Pixel(255-R, 255-G, 255-B);
}

void Effects::updatePixelsGray(int i, int j, int ii)
{
    int R = images[ii].data[i][j].red;
    int G = images[ii].data[i][j].grn;
    int B = images[ii].data[i][j].blu;
    int ave = (R+G+B)/3;
    images[ii].data[i][j] = Pixel(ave, ave, ave);
}

void Effects::setRowCol(int pixelRow, int pixelCol, Bmp& bmp, int& row, int& col, int i, int j)
{
    if (pixelRow < 0 || pixelRow >= bmp.infoHdr.height ||
        pixelCol < 0 || pixelCol >= bmp.infoHdr.width) {
        row = i;
        col = j;
    }
    else if (pixelRow >= 0 && pixelRow < bmp.infoHdr.height &&
             pixelCol >= 0 && pixelCol < bmp.infoHdr.width) {
        row = pixelRow;
        col = pixelCol;
    }
}

void Effects::setBlur(int viewIndex)
{
    for (int ii = 0; ii < static_cast<int>(images.size()); ii++)
    {
        Bmp bmp = images[ii];
        setView(viewIndex, bmp);
        setKernel(BLUR_KERNEL_ID);
        for (int i = viewY; i < (viewY + viewHeight); i++) {
            for (int j = viewX; j < (viewX + viewWidth); j++) {
                int sumR = 0, sumG = 0, sumB = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        int pixelRow = i + k;
                        int pixelCol = j + l;
                        int row, col;
                        setRowCol(pixelRow, pixelCol, bmp, row, col,i,j);
                        sumR += bmp.data[row][col].red * kernel[k + 1][l + 1];
                        sumG += bmp.data[row][col].grn * kernel[k + 1][l + 1];
                        sumB += bmp.data[row][col].blu * kernel[k + 1][l + 1];
                    }
                }
                updatePixels(sumR, sumG, sumB, ii, i, j);
            }
        }
    }
    saveOutput();
}

void Effects::setSharpen(int viewIndex)
{
    for (int ii = 0; ii < static_cast<int>(images.size()); ii++)
    {
        Bmp bmp = images[ii];
        setView(viewIndex, bmp);
        setKernel(SHARPEN_KERNEL_ID);
        for (int i = viewY; i < (viewY + viewHeight); i++) {
            for (int j = viewX; j < (viewX + viewWidth); j++) {
                int sumR = 0, sumG = 0, sumB = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        int pixelRow = i + k;
                        int pixelCol = j + l;
                        int row, col;
                        setRowCol(pixelRow, pixelCol, bmp, row, col,i,j);
                        sumR += bmp.data[row][col].red * kernel[k + 1][l + 1];
                        sumG += bmp.data[row][col].grn * kernel[k + 1][l + 1];
                        sumB += bmp.data[row][col].blu * kernel[k + 1][l + 1];
                    }
                }
                updatePixels(sumR, sumG, sumB, ii, i, j);
            }
        }
    }
    saveOutput();
}

void Effects::setEmboss(int viewIndex)
{
    for (int ii = 0; ii < static_cast<int>(images.size()); ii++)
    {
        Bmp bmp = images[ii];
        setView(viewIndex, bmp);
        setKernel(EMBOSS_KERNEL_ID);
        for (int i = viewY; i < (viewY + viewHeight); i++) {
            for (int j = viewX; j < (viewX + viewWidth); j++) {
                int sumR = 0, sumG = 0, sumB = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        int pixelRow = i + k;
                        int pixelCol = j + l;
                        int row, col;
                        setRowCol(pixelRow, pixelCol, bmp, row, col,i,j);
                        sumR += bmp.data[row][col].red * kernel[k + 1][l + 1];
                        sumG += bmp.data[row][col].grn * kernel[k + 1][l + 1];
                        sumB += bmp.data[row][col].blu * kernel[k + 1][l + 1];
                    }
                }
                updatePixels(sumR, sumG, sumB, ii, i, j);
            }
        }
    }
    saveOutput();
}

void Effects::setInvert(int viewIndex)
{
    for (int ii = 0; ii < static_cast<int>(images.size()); ii++)
    {
        Bmp bmp = images[ii];
        setView(viewIndex, bmp);
        for (int i = viewY; i < (viewY + viewHeight); i++) {
            for (int j = viewX; j < (viewX + viewWidth); j++) {
                updatePixelsInvert(i, j, ii);
            }
        }
    }
    saveOutput();
}

void Effects::setGray(int viewIndex)
{
    for (int ii = 0; ii < static_cast<int>(images.size()); ii++)
    {
        Bmp bmp = images[ii];
        setView(viewIndex, bmp);
        for (int i = viewY; i < (viewY + viewHeight); i++) {
            for (int j = viewX; j < (viewX + viewWidth); j++) {
                updatePixelsGray(i, j, ii);
            }
        }
    }
    saveOutput();
}

void Effects::saveOutput()
{
    for(int i = 0; i < static_cast<int>(images.size()); i++)
    {
        std::string filename = outputs_adr[i];
        if(filename[filename.size()-1] != 'p') 
        {
            filename = filename.substr(0, filename.length() - 1);
        }
        write(images[i], filename);
    }
}
