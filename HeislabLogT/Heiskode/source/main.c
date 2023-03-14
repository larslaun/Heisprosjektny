#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "buttons.h"
#include "doors.h"
#include "elev_control.h"
#include "lights.h"





int main(){
    elevio_init();

    while(elevio_floorSensor()!=0){
        elevio_motorDirection(DIRN_DOWN);
    }
    elevio_motorDirection(DIRN_STOP);

    int queueUp[3] = {5, 5, 5};
    int queueDown[3] = {5, 5, 5};
    int queueCar[4] = {5, 5, 5, 5};

    

    while(1){
        int floor = elevio_floorSensor();

    

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


        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            elevio_stopLamp(1);
            if(elevio_floorSensor() != -1){
                openDoor();
            }
            while(elevio_stopButton()){               
            }
            elevio_stopLamp(0);
            if(elevio_floorSensor() != -1){
                doorTimer();
                while(elevio_obstruction() == 1){
                }
                closeDoor();
            }

            queueUp[3] = {5, 5, 5};
            queueDown[3] = {5, 5, 5};
            queueCar[4] = {5, 5, 5, 5};

            //OG stopp
            //elevio_motorDirection(DIRN_STOP);
            //break;
            //
        }

        controller(queueUp, queueDown, queueCar);

        printf("QueueCar:\n");
        for (int i = 0; i < 4; i++){
            printf("%d\n",queueCar[i]+1);
        }

        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
