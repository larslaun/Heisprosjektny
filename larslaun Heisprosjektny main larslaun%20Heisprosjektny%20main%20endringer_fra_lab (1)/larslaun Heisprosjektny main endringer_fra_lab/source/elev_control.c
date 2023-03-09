#include "elev_control.h"
#include "driver/elevio.h"
#include "doors.h"
#include "lights.h"

int checkIfQueueEmpty(int *queue, int queueSize){
    for (int i=0; i<queueSize; i++){
        if(queue[i]!=5){
            return 0;
        }
    return 1;
}}



void controller(int *queueUp, int *queueDown, int *queueCar){
    carLights(queueCar);

    floorLight();
    int nextFloor;
    if (checkIfQueueEmpty(queueUp,3) == 1){
        if (checkIfQueueEmpty(queueDown,3) == 1){
            if (checkIfQueueEmpty(queueCar,4) == 1){
                elevio_motorDirection(DIRN_STOP);
                return;
            }
        }
    }

    if (checkIfQueueEmpty(queueCar, 4) == 0){
        for (int i=0; i<4; i++){
            if(queueCar[i]!=5){
                nextFloor = queueCar[i];
            }
        }

    }

    printf("QueueCar:\n");
    for (int i = 0; i < 4; i++){
        printf("%d\n",queueCar[i]+1);
    }

    goToFloor(nextFloor, queueUp, queueDown, queueCar);
}



void goToFloor(int nextFloor, int *queueUp, int *queueDown, int *queueCar){
    int currentFloor = elevio_floorSensor(); 

    if(currentFloor != -1){

        if (nextFloor == currentFloor){
            elevio_motorDirection(DIRN_STOP);
            removeFromQueue(queueUp, queueDown, queueCar, nextFloor);
            
            printf("QueueCar:\n");
            for (int i = 0; i < 4; i++){
                printf("%d\n",queueCar[i]+1);
            }

            doorWhenFloor();
            
        }

        
        if (nextFloor > currentFloor){
            elevio_motorDirection(DIRN_UP);
        }
        if (nextFloor < currentFloor){
            elevio_motorDirection(DIRN_DOWN);
        }

        
    }


}