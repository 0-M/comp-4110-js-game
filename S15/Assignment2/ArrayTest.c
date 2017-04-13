/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment0xpe0y: ProgramName          */
/*                                                */
/* Approximate completion time: ... minutes       */
/**************************************************/

/*
   This program... (description of what the program does)
*/

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

int main(int argc, char *argv[])
{
    int capacity,numElementsToAdd,i,numElements,checkedData;
    ArrayPtr ar;
    ar = NULL;
    capacity = 0;
    numElementsToAdd = 5;
    numElements = 0;


    printf("How big would you like your array to be? ");
    scanf("%d",&capacity);
    ar = initArray(capacity);
    printf("\n");
    printf("Adding five elements to the array.\n");
    for(i = 0; i < numElementsToAdd; i++)
    {
        add(&ar,&numElements,&capacity,(i * 10)+10,i);
    }
    printf("\n");

    display(ar,numElements);

    printf("Checking the data at element 3.\n");
    checkedData = check(ar,numElements,3);
    printf("The data at element 3 is: %d\n",checkedData);

    printf("\n");

    printf("Adding 60 as the 6th element of the array.\n");
    add(&ar,&numElements,&capacity,60,6);
    display(ar,numElements);

    printf("\n");

    printf("Replacing the data at position 4 with 7.\n");
    replaceDat(ar,numElements,4,7);
    display(ar,numElements);

    printf("\n");

    printf("Removing element number 4.\n");
    removeDat(ar,&numElements,4);
    display(ar,numElements);

    printf("\n");

    printf("Removing all the elements from the array.\n");
    emptyArr(ar,&numElements);
    display(ar,numElements);

    printf("\n");

    printf("Freeing the array.\n");
    destroy(ar,numElements,capacity);


    return 0;
}
