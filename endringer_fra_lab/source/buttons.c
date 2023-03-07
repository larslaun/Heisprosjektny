#include "buttons.h"

void addToQueue(int *queue, int floor, int queueSize){
    
    
    for (int i = 0; i < queueSize; i++){
        for (int k = 0; k < queueSize; k++){
            if(queue[k] == floor) {
                return;
        }}
        if (queue[i] == 5){
            queue[i] = floor;
            printf("Added a floor to queue\n");
        }
    }
}
    

void removeFromQueue(int *queueUp, int* queueDown, int* queueCar, int floor){
      for (int i=0; i<3; i++){
        if(queueUp[i]==floor){
            queueUp[i]= 5;
        }
        if(queueDown[i]==floor){
            queueDown[i]= 5;
        }
      }
      
      for (int i=0; i<4; i++){
        if(queueCar[i]==floor){
            queueCar[i]= 5;
        }
      }

}

