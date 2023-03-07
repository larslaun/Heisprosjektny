#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "buttons.h"
#include "doors.h"
#include "elev_car.h"
#include "elev_control.h"
#include "lights.h"





int main(){
    elevio_init();

    elevio_motorDirection(DIRN_UP);
    MotorDirection currentMotorDirection = DIRN_UP;

    int nextFloor = 3; 

    int queueUp[3] = {5, 5, 5};
    int queueDown[3] = {5, 5, 5};
    int queueCar[4] = {1, 5, 5, 5};

    while(1){
        int floor = elevio_floorSensor();
        //printf("floor: %d \n",floor);



        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);

                if (btnPressed == 1){
                   
                    if (b == 0){
                        addToQueue(queueUp, f, 3);
                    }

                    if (b == 1){
                        addToQueue(queueDown, f, 3);
                    }
                    

                    if (b == 2){
                        addToQueue(queueCar, f, 4);
                    }
                }

                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        printf("QueueUp:\n");
        for (int i = 0; i < 3; i++){
            printf("%d\n",queueUp[i]);
        }
        printf("\n");

        printf("QueueDown:\n");
        for (int i = 0; i < 3; i++){
            printf("%d\n",queueDown[i]);
        }
        printf("\n");

        printf("QueueCar:\n");
        for (int i = 0; i < 4; i++){
            printf("%d\n",queueCar[i]);
        }
        printf("\n");

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }

        goToFloor(queueUp, queueDown, queueCar, nextFloor);

        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
