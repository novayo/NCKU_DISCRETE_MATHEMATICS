#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef enum { false, true } bool;
#define DOG 2
#define CHICKEN 1
#define RICE 0

#define RIGHT 1
#define LEFT 0
#define IDLE -1

int arr[3] = {RIGHT, RIGHT, RIGHT}; // 0 -> rice, 1 -> chicken, 2 -> dog
bool shipPos = RIGHT;
char answer[1000] = {'\0'};

bool chooseWhichOnBoat();
void shipMove();
void reset();
void printall();

int main(){
    srand(time(NULL));
    while(true){
        if (chooseWhichOnBoat() == false) { // for reset (might encounter deadlock)
            reset();
            continue;
        }
        // printall();
        shipMove();
        // printall();
        
        char tmp[100] = {'\0'};
        for (int i=0; i<3; i++){
            if (arr[i] == -1){
                strcat(tmp, "IDLE  ");
            } else if (arr[i] == 0){
                strcat(tmp, "LEFT  ");
            } else if (arr[i] == 1){
                strcat(tmp, "RIGHT ");
            }   
        }
        strcat(tmp, "\n");
        strcat(answer, tmp);
        if (arr[0] == LEFT && arr[1] == LEFT && arr[2] == LEFT) break;
    }
    
    printf("%s\n", answer);
    return 0;
}

void shipMove(){
    if (shipPos == RIGHT){
        shipPos = LEFT;        
    } else if (shipPos == LEFT){
        shipPos = RIGHT;
    }

    for(int i=0; i<3; i++){
        if (arr[i] == IDLE){
            arr[i] = shipPos;
        } 
    }
}

bool chooseWhichOnBoat(){
    int randNumOfChosen = rand()%2 + 1; // random select 1 or 2 animal
    int random1 = -1;
    int random2 = -1;
    int tmp1 = -1;
    int tmp2 = -1;
    int count = 0;
    switch (randNumOfChosen)
    {
        case 1:
            while(true){
                if (count++ >= 100) return false; // for reset (might encounter deadlock)
                random1 = rand()%3; // rice or chicken or dog
                if (shipPos != arr[random1]){ // choose ship side animal
                    continue;
                } else{
                    break;
                }                                
            }
            
            tmp1 = arr[random1];
            arr[random1] = IDLE;
            break;
        case 2:
            while(true){
                if (count++ >= 100) return false; // for reset (might encounter deadlock)
                random1 = rand()%3;
                random2 = rand()%3;
                if (shipPos != arr[random1] || 
                    shipPos != arr[random2] ){ // choose ship side animal
                    continue;
                } else if (random1 == random2 || 
                           abs(random1 - random2) == 1){ // restriction for the question
                    continue;
                } else {
                    break;
                }
            }
            tmp1 = arr[random1];
            tmp2 = arr[random2];
            arr[random1] = IDLE;
            arr[random2] = IDLE;
            break;
        default: 
            break;
    }
    return true;
}

void reset(){
    arr[0] = RIGHT;
    arr[1] = RIGHT;
    arr[2] = RIGHT;
    shipPos = RIGHT;
    memset(answer, 0, sizeof answer);
}

void printall(){
    for (int i=0; i<3; i++){
        if (arr[i] == -1){
            printf("IDLE ");
        } else if (arr[i] == 0){
            printf("LEFT ");
        } else if (arr[i] == 1){
            printf("RIGHT ");
        }
    }
    printf("\n\n");
}