#include "buttons.h"

void addToQueue(int *queue, int floor, int queueSize){
    
    
    for (int i = 0; i < queueSize; i++){
        for (int k = 0; k < queueSize; k++){
            if(queue[k] == floor) {
                return;
        }}
        if (queue[i] == 5){
            queue[i] = floor;
        }
    }
}
    

void removeFromQueue(int *queueUp, int* queueDown, int* queueCar, int floor){
      for (int i=0; i<3; i++){
        if(queueUp[i]==floor){
            //Ny kode for å pushe queue til venstre ved fjerning av element
            for (int j = i; j < 2; j++){
                queueUp[j] = queueUp[j+1];
            }
            queueUp[2] = 5;


            
        }
        if(queueDown[i]==floor){
             //Ny kode for å pushe queue til venstre ved fjerning av element
            for (int j = i; j < 2; j++){
                queueDown[j] = queueDown[j+1];
            }
            queueDown[2] = 5;
        }
      }
      
      for (int i=0; i<4; i++){
        if(queueCar[i]==floor){
             //Ny kode for å pushe queue til venstre ved fjerning av element
            for (int j = i; j < 3; j++){
                queueCar[j] = queueCar[j+1];
            }
            queueCar[3] = 5;
        }
      }

    
}



