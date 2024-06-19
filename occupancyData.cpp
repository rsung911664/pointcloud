#include "occupancyData.h"

extern unsigned char** occupancyData;
extern int occupancyHeight;
extern int occupancyWidth;

void occupancyDciInit(Int height, Int width, int frameNum, std::string name) {
    //如果occupancy的大小是320x320要把height跟width除4
    occupancyHeight = height/4;
    occupancyWidth = width/4;

    int npos_GOF0_, npos_x;
    npos_GOF0_ = name.find("_GOF0_");
    npos_x = name.find_last_of("/");
    char* temp = new char;
    std::string occupancyName = name.substr(npos_x + 1, npos_GOF0_ - npos_x - 1) + "_GOF0_occupancy_" +
        itoa(occupancyWidth, temp, 10) + "x" + itoa(occupancyHeight, temp, 10) +
        "_8bit_p420.yuv";

    occupancyData = new unsigned char* [frameNum/2];
    for (int i = 0; i < frameNum/2; i++)
        occupancyData[i] = (unsigned char*)malloc(sizeof(unsigned char) * occupancyHeight * occupancyWidth * 3 / 2);
    FILE* oriOccupancy = fopen(occupancyName.data(), "rb+");
    if (oriOccupancy != nullptr){        
        for (int i = 0; i < frameNum / 2; i++)
            fread(occupancyData[i], sizeof(unsigned char), occupancyWidth * occupancyHeight * 3 / 2, oriOccupancy);
    }
    if (oriOccupancy != NULL) fclose(oriOccupancy);

}

void checkData(int frameNum, int height, int width) {
    for (int i = 0; i < frameNum; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                std::cout << occupancyData[i][j * occupancyWidth + k] - 0 << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-========================-" << std::endl;
    }
}