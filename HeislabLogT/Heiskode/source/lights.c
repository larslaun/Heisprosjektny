#include "lights.h"
#include "driver/elevio.h"


void floorLight(){
    int floor = elevio_floorSensor();
    if (floor != -1){
        elevio_floorIndicator(floor);
    }
}

void orderLights(int *queueCar, int *queueUp, int *queueDown){
    for (int i=0; i < 4; i++){
        if (queueCar[i] != 5){
            elevio_buttonLamp(i, BUTTON_CAB, 1);
        }
        else {
            elevio_buttonLamp(i, BUTTON_CAB, 0);
        }
    }

    for (int i=0; i < 3; i++){
        if (queueUp[i] != 5){
            elevio_buttonLamp(i, BUTTON_HALL_UP, 1);
        }
        else {
            elevio_buttonLamp(i, BUTTON_HALL_UP, 0);
        }
    }

    for (int i=0; i < 3; i++){
        if (queueDown[i] != 5){
            elevio_buttonLamp(i, BUTTON_HALL_DOWN, 1);
        }
        else {
            elevio_buttonLamp(i, BUTTON_HALL_DOWN, 0);
        }
    }
    
}


