#include "elev_control.h"
#include "driver/elevio.h"
#include "doors.h"
#include "lights.h"

int checkIfQueueEmpty(int *queue, int queueSize)
{
    for (int i = 0; i < queueSize; i++)
    {
        if (queue[i] != 5)
        {
            return 0;
        }
        return 1;
    }
}

void controller(int *queueUp, int *queueDown, int *queueCar)
{
    orderLights(queueCar, queueUp, queueDown);
    floorLight();

    // Global currentfloor?

    int currentFloor = elevio_floorSensor();

    // int nextFloor;

    if (checkIfQueueEmpty(queueUp, 3) == 1)
    {
        if (checkIfQueueEmpty(queueDown, 3) == 1)
        {
            if (checkIfQueueEmpty(queueCar, 4) == 1)
            {
                elevio_motorDirection(DIRN_STOP);
                return;
            }
        }
    }

    int nextFloor = queueCar[0];
    if (queueCar[0] == 5)
    {
        nextFloor = queueUp[0];
    }
    if (queueUp[0] == 5)
    {
        nextFloor = queueDown[0];
    }

    if (currentFloor != -1)
    {

        if (checkIfQueueEmpty(queueCar, 4) == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                if (queueCar[i] != 5)
                {
                    nextFloor = queueCar[i];
                    break;
                }
            }
            if (nextFloor > currentFloor)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (queueCar[i] != 5)
                    {
                        if (currentFloor < queueCar[i])
                        {
                            if (queueCar[i] < nextFloor)
                            {
                                nextFloor = queueCar[i];
                            }
                        }
                    }
                }
            }

            if (nextFloor < currentFloor)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (queueCar[i] != 5)
                    {
                        if (currentFloor > queueCar[i])
                        {
                            if (queueCar[i] > nextFloor)
                            {
                                nextFloor = queueCar[i];
                            }
                        }
                    }
                }
            }
        }

        if (nextFloor > currentFloor)
        {
            if (elevio_floorSensor() != -1)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (queueUp[i] != 5)
                    {
                        if (currentFloor < queueUp[i])
                        {
                            if (queueUp[i] < nextFloor)
                            {
                                nextFloor = queueUp[i];
                            }
                        }
                    }
                }
            }
        }


        else if (nextFloor < currentFloor)
        {
            for (int i = 0; i < 3; i++)
            {
                if (queueDown[i] != 5)
                {
                    if (currentFloor > queueDown[i])
                    {
                        if (queueDown[i] > nextFloor)
                        {
                            nextFloor = queueDown[i];
                        }
                    }
                }
            }
        }
    }
    
    printf("QueueCar:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", queueCar[i] + 1);
    }

    printf("Nextfloor: ");
    printf("%d\n", nextFloor);

    printf("Currentfloor: ");
    printf("%d\n", currentFloor);

    //ny
    currentFloor = elevio_floorSensor();
    //

    goToFloor(nextFloor, queueUp, queueDown, queueCar, currentFloor);
}

void goToFloor(int nextFloor, int *queueUp, int *queueDown, int *queueCar, int currentFloor){

    if (currentFloor != -1)
        {

        if (nextFloor == currentFloor)
        {
            printf("\nSkal stoppe nå\n");
            elevio_motorDirection(DIRN_STOP);
            removeFromQueue(queueUp, queueDown, queueCar, nextFloor);

            doorWhenFloor();
        }

        if (nextFloor > currentFloor)
        {
            elevio_motorDirection(DIRN_UP);
        }
        if (nextFloor < currentFloor)
        {
            elevio_motorDirection(DIRN_DOWN);
        }
    }   
}