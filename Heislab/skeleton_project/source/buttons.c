#include "buttons.h"

void addToQueue(queueItem &queue){
    for(int floor; floor < 4; floor++){
        for (int button; button < 3; button++){
            if (elevio_callButton(floor, button) == 1){
                queueItem new;
                new.floor = floor;
                new.button = button;
                
            }
        }
    }
}

