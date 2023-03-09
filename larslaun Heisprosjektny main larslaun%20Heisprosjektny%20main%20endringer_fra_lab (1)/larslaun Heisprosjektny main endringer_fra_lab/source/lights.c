#include "lights.h"
#include "driver/elevio.h"


void floorLight(){
    int floor = elevio_floorSensor();
    if (floor != -1){
        elevio_floorIndicator(floor);
    }
}

void carLights(int *queueCar){
    for (int i; i < 4; i++){
        if (queueCar[i] != 5){
            elevio_buttonLamp(i, BUTTON_CAB, 1);
        }
        else {
            elevio_buttonLamp(i, BUTTON_CAB, 0);
        }
    }
    
}

void callLights(){
    
}

