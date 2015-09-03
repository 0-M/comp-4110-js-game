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
   selection sort algorithm.
*/

#include "memswap.h"
#include "stdio.h"

void selection_sort(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	int i,j,index; /* Declaration */
	byte *comp,*curr; /* Declaration */

	for(i = 0;i < size-1;i++)
		{
		curr = data + (i * elementsize); /* Sets the one to compare against all the others */
		index = i; /* Initialization */

		for(j = i + 1;j < size;j++)
			{
				comp = data + (j * elementsize); /* Sets the one being to compared */

				if((*p_cmp_f)(curr,comp) > 0) /* If the first number compared is bigger than the second, this will return true */
				{
					index = j; /* This will end up being the highest index, which will contain the lowest number */
				}
			}
                memswap(curr,data + (index * elementsize),elementsize); /* swap the current number with the number at the lowest number */

		}
}
