#include "doors.h"

void openDoor(){
    elevio_doorOpenLamp(1);
}

void closeDoor(){
    elevio_doorOpenLamp(0);
}

void doorTimer(){
    sleep(3);
}

void doorWhenFloor(){
    openDoor();
    doorTimer();
    while(elevio_obstruction() == 1){
    }
    closeDoor();
}