#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "LinkedList.h"



int main(int argc, char *argv[])
{
    srand(time(NULL)); //Give rand a different seed everytime
    Data r,checked;
    int capacity,i,outliers;
    capacity = 10000;
    outliers = 0;
 struct timespec start, stop;
    double accum;

    LinkedListPtr list = initLinkedList(); //Creates a linked list

    if(RAND_MAX > capacity)
    {
        outliers = capacity/2;
    }
    else
    {
        outliers = RAND_MAX/2;
    }

    for(i = 0; i < capacity; i++)
    {
        r = rand() % capacity;
        add(list,r,i);
    }




 clock_gettime( CLOCK_MONOTONIC, &start);


      //checked = check(list,outliers); //Check the data in the middle

    //replaceData(list,outliers,rand() % capacity);

     add(list,rand() % capacity,0);

     //addAfter(list,rand() % capacity,outliers-1);

     //removeData(list,0);

     //removeDataAfter(list,outliers-1);

     //removeOutliers(list,outliers);

    //smoothList(list);


       clock_gettime( CLOCK_MONOTONIC, &stop);
     accum = ( stop.tv_sec - start.tv_sec )
             + (double)( stop.tv_nsec - start.tv_nsec )
               / (double)CLOCKS_PER_SEC;
    printf( "CPU TIME: %lf\n", accum );

    printf("Displaying 10 elements: \n");
    display(list,10);

    /*Test code for 5 elements*/

//    display(list);
//
//    replaceData(list,2,rand() % (capacity)* 10);
//    printf("Replacing the data at position 2 with a random integer\n");
//
//    display(list);
//
//    checked = check(list,2);
//    printf("Checking the data at position 2.\n");
//    printf("\n");
//    printf("Data at position 2 is: %d\n",checked);
//    printf("\n");
//
//    add(list,72,2);
//    printf("Adding an element at position 2.\n");
//
//    display(list);
//
//    removeData(list,2);
//    printf("Removing the element at position 2.\n");
//
//    display(list);
//
//    addAfter(list,72,1);
//    printf("Adding element after position 1.\n");
//
//    display(list);
//
//    removeDataAfter(list,1);
//    printf("Removing element after position 1.\n");
//
//
//    display(list);
//
//    removeOutliers(list, capacity/2);
//    printf("Removing outliers.\n");
//
//    display(list);
//
//    smoothList(list);
//    printf("Smoothing the list.\n");
//
//    display(list);


    return 0;
}
