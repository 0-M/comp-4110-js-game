#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "queue.h"



typedef struct Runway
{

    int vacant;
    int timeTillVacant;
    Data planeUsing;
} Runway,*RunwayPtr;

float generateProbability();
int generateRandom(int from, int to);


int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    QueuePtr airQ = initQueue();
    QueuePtr groundQ = initQueue();
    RunwayPtr runway = (RunwayPtr)malloc(sizeof(Runway)); //Initialize runway
    runway -> vacant = 1;
    runway -> timeTillVacant = -1;
    runway -> planeUsing = 0;

    float randomAir,randomGr,arrivalAirProb,arrivalGroundProb;
    int randomID,timeDuration,i,timeSpent;
    randomAir = 0;
    randomGr = 0;
    randomID = 0;
    arrivalAirProb = 0;
    arrivalGroundProb = 0;
    timeDuration = 0;
    timeSpent = 0;

    printf("How long would you like to run this program for(1-20)? ");
    scanf("%d",&timeDuration);

    printf("Enter the air arrival probability(0-1): ");
    scanf("%f",&arrivalAirProb);

    printf("Enter the ground arrival probability(0-1): ");
    scanf("%f",&arrivalGroundProb);

    printf("\n\n");

    for(i = 0; i < timeDuration; i++)
    {
        Sleep(1000);
        timeSpent++;
        randomAir = generateProbability();
        randomGr = generateProbability();
        if(runway -> vacant == 0) //Runway is not vacant
        {
            runway -> timeTillVacant = runway -> timeTillVacant -1;
        }
        if(runway -> timeTillVacant == 0)//Runway is not vacant
        {
            printf("The runway is now vacant.\n");
            runway -> vacant = 1; //Runway is vacant
            runway -> planeUsing = 0;
        }
        if(randomAir < arrivalAirProb)//One plane could join air queue
        {
            randomID = generateRandom(100, 999);
            printf("Adding plane %d to airQueue.\n",randomID);
            enqueue(airQ,randomID);
        }

        if(randomAir < (arrivalAirProb * arrivalAirProb)) //Another plane could join air queue
        {
            randomID = generateRandom(100, 999);
            printf("Adding plane %d to airQueue.\n",randomID);
            enqueue(airQ,randomID);
        }

        if(randomGr < arrivalGroundProb) //One plane could join ground queue
        {
            randomID = generateRandom(100, 999);
            printf("Adding plane %d to groundQueue.\n",randomID);
            enqueue(groundQ,randomID);
        }

        if(runway -> vacant == 1) //If the runway is vacant
        {
            if(!(isEmpty(airQ)))//If airQueue isn't empty
            {
                runway -> vacant = 0; //Runway is not vacant
                runway -> planeUsing = dequeue(airQ);
                runway -> timeTillVacant = 2;
            }
            else if (!(isEmpty(groundQ)))  //If airQueue is empty
            {
                runway -> vacant = 0; //Runway is not vacant
                runway -> planeUsing = dequeue(groundQ);
                runway -> timeTillVacant = 2;
            }

        }



        printf("Time since start: %d\n",timeSpent);
        if(runway -> vacant == 1)
        {
            printf("The runway is vacant.\n");
        }
        else
        {
            printf("The runway is not vacant, but will be vacant in %d seconds.\n",runway -> timeTillVacant);
            printf("Airplane using the runway:  %d\n",runway -> planeUsing);
        }

        printf("Size of airQueue: %d.\n",getSize(airQ));
        printf("Size of groundQueue: %d.\n",getSize(groundQ));


        printf("\n\n\n");

    }






    return 0;
}

float generateProbability()
{
    int n = rand();
    float probability = n / (float) RAND_MAX;
    return probability;
}


int generateRandom(int from, int to)
{
    int n  =  rand() % (to - from + 1);
    return n + from;
}
