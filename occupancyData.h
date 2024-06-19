#ifndef __occupancyData__
#define __occupancyData__

#include <TLibCommon/CommonDef.h>
#include <string>

unsigned char** occupancyData;
int occupancyHeight;
int occupancyWidth;

void occupancyDciInit(Int height, Int width, int frameNum, std::string occupancyName);
void checkData();
#endif