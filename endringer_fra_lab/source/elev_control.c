#include "elev_control.h"
#include "driver/elevio.h"

int checkIfQueueEmpty(int *queue, int queueSize){
    for (int i=0; i<queueSize; i++){
        if(queue[i]!=5){
            return 0;
        }
    return 1;
}}



void goToFloor(int *queueUp, int *queueDown, int *queueCar, int nextFloor){
    if (checkIfQueueEmpty(queueUp,3) == 1){
        if (checkIfQueueEmpty(queueDown,3) == 1){
            if (checkIfQueueEmpty(queueCar,4) == 1){
                elevio_motorDirection(DIRN_STOP);
            }
        }
    }

    int floor;
    if(elevio_floorSensor()!=-1){
        floor = elevio_floorSensor();
    }

    if (nextFloor > floor){
        elevio_motorDirection(DIRN_UP);
    }
    if (nextFloor < floor){
        elevio_motorDirection(DIRN_DOWN);
    }

    if (nextFloor == floor){
        elevio_motorDirection(DIRN_STOP);
        removeFromQueue(queueUp, queueDown, queueCar, floor);
    }


}
