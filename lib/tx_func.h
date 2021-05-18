#ifndef TX_FUNC_H_
#define TX_FUNC_H_

#include "mainLogic.h"

void viewUsage();
void addUsage();
void payUsage();
void logTX(long id, int type, int idr, float kwh, float txKWH);

#endif