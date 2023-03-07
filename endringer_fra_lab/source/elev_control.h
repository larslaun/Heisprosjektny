#pragma once
#include "driver/elevio.h"



int checkIfQueueEmpty(int *queue, int queueSize);
void clearQueues();
void goToFloor(int *queueUp, int *queueDown, int *queueCar, int nextFloor);