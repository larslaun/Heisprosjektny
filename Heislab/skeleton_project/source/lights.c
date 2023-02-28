#include "lights.h"
#include "elevio.h"


void floorLight(){
    int floor = elevio_floorSensor();
    if (floor != -1){
        elevio_floorIndicator(floor);
    }
}

void carLights(){
    int floorOrdered;
    elevio_buttonLamp(floorOrdered, ButtonType::BUTTON_CAB, true);
}

void callLights(){
    int
}

