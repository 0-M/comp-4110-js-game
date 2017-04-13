/*****************************************************/
/* Skeleton provided by S. Bassil (Fall 2014)        */
/*                                                   */
/* Programmer:                                       */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   This function sorts an array of elements using the
   bubble sort algorithm.
*/

#include "memswap.h"

void bubble_sort(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	int i,j; /* Declaration */
	byte *comp, *curr; /* Declaration */
		for(i = 0;i < size-1;i++)
		{
			curr = data + (i * elementsize); /* Sets the element to be compared to all the elements */
			for(j = i + 1;j < size;j++)
			{
				comp = data + (j * elementsize); /* Current element being checked */
				if((*p_cmp_f)(curr,comp) > 0) /* If the first number compared is bigger than the second, this will return true */
				{
					memswap(curr,comp, elementsize); /* Swaps */
				}
			}
		}
}
