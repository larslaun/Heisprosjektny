#pragma once
#include "driver/elevio.h"
#include "stdbool.h"

struct Door{
    bool doorOpen;
    bool doorObstruction;
    int doorTimer;
};

void openDoor();
void closeDoor();