#include "lights.h"
#include "driver/elevio.h"


void floorLight(){
    int floor = elevio_floorSensor();
    if (floor != -1){
        elevio_floorIndicator(floor);
    }
}

void carLights(){
    int floorOrdered;
    elevio_buttonLamp(floorOrdered, BUTTON_CAB, 1);
}

void callLights(){
    
}

