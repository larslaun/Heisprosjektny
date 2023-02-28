#pragma once
#include elevio.h

struct Door{
    bool doorOpen;
    bool doorObstruction;
    int doorTimer;
}

void openDoor();
void closeDoor();