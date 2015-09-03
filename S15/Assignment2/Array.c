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

ArrayPtr initArray(int capacity)
{
    Data *arr;
    ArrayPtr arPtr;
    arr = (Data *)malloc(capacity * sizeof(Data));
    arPtr = arr;
    printf("Successfully created an array of with a capacity of %d elements.\n",capacity);
    return arPtr;
}

Data check(ArrayPtr ar,int num_elements,int position)
{

    if(position > num_elements)
    {
        return -1;
        printf("That position is invalid.\n");
    }
    else
    {
        return ar[position-1];
    }




}

void add(ArrayPtr* par, int* p_num_elements, int * pcapacity, Data data, int position)
{
    int i;
    i = 0;
    *p_num_elements = *p_num_elements + 1;
    if(position > *p_num_elements)
    {
        printf("That position is invalid.\n");
    }
    else
    {
        if(position == 0)
        {
            *(par[0]) = data;
        }
        else if(position == *p_num_elements)
        {
            *(par[0] + *p_num_elements-1) = data;
        }
        else
        {
            for(i = *p_num_elements-1; i > position-1; i--) //move everything up one space
            {
                *(par[0] + i) = *(par[0] + i - 1);
            }

            *(par[0] + position) = data; //inserts the new data in after everything has been shifted up

        }

        printf("%d has been successfully inserted at position %d.\n",data,position);
    }
}


void replaceDat(ArrayPtr ar, int num_elements, int position, Data data)
{
    if(position > num_elements)
    {
        printf("That position is invalid.\n");
    }
    else
    {
        int old;
        old = ar[position-1];
        ar[position-1] = data;
        printf("Successfully changed the data at position %d from %d to %d.\n",position,old,ar[position-1]);
    }

}


void display(ArrayPtr ar, int num_elements)
{
    int i;
    if(num_elements == 0)
    {
        printf("There is no data to display.\n");
    }
    else
    {
        printf("Displaying the array\n");
        for(i = 0; i < num_elements; i++)
        {
            printf("%d: %d\n",i+1,ar[i]);
        }
    }

}

void removeDat(ArrayPtr ar, int* p_num_elements, int position)
{
    int i;
    if(position > *p_num_elements)
    {
        printf("That position is invalid.\n");
    }
    else
    {
        if(*p_num_elements == 0)
        {
            printf("The array is empty, no data can be removed");
        }
        else
        {
            for(i = position; i < *p_num_elements; i++)
            {
                ar[i - 1] = ar[i];
            }
            printf("Successfully removed element %d.\n",position);
            *p_num_elements = *p_num_elements - 1;
        }
    }



}

void emptyArr(ArrayPtr ar, int* p_num_elements)
{
    int i;
    if(*p_num_elements == 0)
    {
        printf("The array is already empty.\n");
    }
    else
    {
        for(i = 0; i < *p_num_elements; i++)
        {
            ar[i] = 0;
        }

        *p_num_elements = 0;
        printf("The array had been emptied.\n");
    }


}


int isEmpty(ArrayPtr ar, int* p_num_elements)
{
    if(*p_num_elements == 0)
    {
        printf("The array is empty.\n");
        return 1;
    }
    else
    {
        printf("The array is not empty.\n");
        return 0;
    }
}

ArrayPtr destroy(ArrayPtr ar, int num_elements,int capacity)
{
    int i;

    if(isEmpty(ar,&num_elements) == 0)
    {
        for(i = 0; i < num_elements; i++)
        {
            free(ar);
        }
    }
    ar = NULL;
    printf("The array had been destroyed.\n");
    return ar;
}
