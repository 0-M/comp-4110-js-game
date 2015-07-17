#include <stdio.h>
#include <stdlib.h>
#include "Array.h"


ArrayPtr initArray(int capacity)
{
    Data *arr;
    ArrayPtr arPtr;
    arr = (Data *)malloc(capacity * sizeof(Data));
    arPtr = arr;
    printf("Successfully created an array\n");
    return arPtr;
}

void check(ArrayPtr ar,int num_elements,int position)
{

    if(position > num_elements)
    {
        printf("That position is invalid.\n");
    }
    //printf("The data at position %d is: %d\n",position,ar[position-1]);



}

void addAfter(ArrayPtr* par, int* p_num_elements, int * pcapacity, Data data, int position) // Change the add function you already have
{

    int i;
    i = 0;
    *p_num_elements = *p_num_elements + 1;
    *pcapacity = *pcapacity + 1;
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
            for(i = *p_num_elements; i > position-1; i--) //move everything up one space
            {
                *(par[0] + i) = *(par[0] + i - 1);
            }

            *(par[0] + position) = data; //inserts the new data in after everything has been shifted up

        }

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


void display(ArrayPtr ar, int toDisplay) //Need to change to only display a few elements
{
    int i;
    printf("Displaying the array\n");
    for(i = 0; i < toDisplay; i++)
    {
        printf("%d: %d\n",i+1,ar[i]);
    }
    printf("\n");
}

void removeDatAfter(ArrayPtr ar, int* p_num_elements, int position)//Change the remove function you already have
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
            for(i = position+1; i < *p_num_elements; i++)
            {
                ar[i - 1] = ar[i];
            }
            *p_num_elements = *p_num_elements - 1;
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
            *p_num_elements = *p_num_elements - 1;
        }
    }



}


void removeOutliers(ArrayPtr ar,int* p_num_elements,int value)
{
    int i,numElements;
    numElements = *p_num_elements;

    for(i = 0; i < numElements; i++)
    {
        if(ar[i] >= value)
        {
            removeDat(ar,p_num_elements,i+1);
            i = i-1;
            numElements--;
        }
    }




}




ArrayPtr smoothList(ArrayPtr ar,int* p_num_elements,int * pcapacity)
{
    int numElements,*p1,*p2,z,x,count;
    x = 0;
    z = 1;
    count = 0;
    p1 = &ar[x];
    p2 = &ar[z];
    numElements = *p_num_elements;
    do
    {
        add(&ar,p_num_elements,pcapacity,(*p1 + *p2)/2,x+1);
        p1 = &ar[z + 1]; //Basically p1 = p2
        p2 = &ar[z + 2];
        z = z + 2;
        x = z -1;
        count++;



    }
    while(count < numElements-1);




    return ar;
}
