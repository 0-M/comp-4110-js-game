#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"

int main(int argc, char *argv[])
{

    srand(time(NULL)); //Give rand a different seed everytime
    ArrayPtr ar;
    ar = NULL;
    int capacity,i,r,numElements,size,outliers;
    capacity = 10000;
    size = 0;
    numElements = 0;
    outliers = 0;
 struct timespec start, stop;
    double accum;


    if(RAND_MAX > capacity)
    {
        outliers = capacity/2;
    }
    else
    {
        outliers = RAND_MAX/2;
    }

    if(capacity % 2 == 0)
    {
        size = (capacity * 2);
    }
    else
    {
        size = (capacity * 2)-1;
    }
    ar = initArray(size);


    for(i = 0; i < capacity; i++) //Filling the array
    {
        r = rand() % capacity;
        ar[i] = r;
        numElements++;
    }



    clock_gettime( CLOCK_MONOTONIC, &start);

    //check(ar,numElements,outliers); //Check the data in the middle

    //replaceDat(ar,numElements,outliers,rand() % capacity); //Replace the data in the middle

    //addAfter(&ar,&numElements, &capacity,rand() % capacity,0); //Add at the start

    //addAfter(&ar,&numElements, &capacity,rand() % capacity,outliers-1); //Add at the middle

    //removeDatAfter(ar,&numElements,0); //Remove at start

    //removeDatAfter(ar,&numElements,outliers-1);//Remove at middle

    //removeOutliers(ar,&numElements,outliers); //Remove outliers

   ar = smoothList(ar,&numElements,&capacity); //Smooth the list


       clock_gettime( CLOCK_MONOTONIC, &stop);
     accum = ( stop.tv_sec - start.tv_sec )
             + (double)( stop.tv_nsec - start.tv_nsec )
               / (double)CLOCKS_PER_SEC;
    printf( "CPU time in microseconds: %lf\n", accum );

    printf("Displaying 10 elements: \n");
    display(ar,10);




    /* Test code for 5 elements */

//
//    replaceDat(ar,numElements,2,rand() % (capacity)* 10);
//    printf("Replacing the data at position 2 with a random integer\n");
//
//    display(ar,numElements);
//
//    printf("Checking the data at position 2.\n");
//    check(ar,numElements,2);
//
//    printf("\n");
//
//    add(&ar,&numElements,&capacity,72,1);
//    printf("Adding an element at position 2.\n");
//
//    display(ar,numElements);
//
//    removeDat(ar,&numElements,2);
//    printf("Removing the element at position 2.\n");
//
//    display(ar,numElements);
//
//    addAfter(&ar,&numElements,&capacity,72,1);
//    printf("Adding element after position 1.\n");
//
//    display(ar,numElements);
//
//    removeDatAfter(ar,&numElements,1);
//    printf("Removing element after position 1.\n");
//
//    display(ar,numElements);
//
//    removeOutliers(ar,&numElements,3);
//    printf("Removing outliers.\n");
//
//    display(ar,numElements);
//
//    ar =  smoothList(ar,&numElements,&capacity);
//    printf("Smoothing the list.\n");
//
//    display(ar,numElements);







    return 0;
}
