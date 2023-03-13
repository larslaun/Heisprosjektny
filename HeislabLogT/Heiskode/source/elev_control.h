#pragma once
#include "driver/elevio.h"



int checkIfQueueEmpty(int *queue, int queueSize);


void controller(int *queueUp, int *queueDown, int *queueCar);

void goToFloor(int nextFloor, int *queueUp, int *queueDown, int *queueCar, int currentFloor);



