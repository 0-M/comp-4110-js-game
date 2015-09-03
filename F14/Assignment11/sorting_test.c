/*****************************************************/
/* Skeleton provided by S. Bassil (Fall 2014)        */
/*                                                   */
/* Programmer:                                       */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

/*
   Declaration of function p_cmp_f.
*/

int p_cmp_f(byte *element1, byte *element2);

/*
   This program reads in integers from the keyboard.
   Then, it sorts those integers using the one or the
   other of the available sorting algorithms (bubble
   sort, selection sort, merge sort and quick sort).
   The sorted integers are displayed to the user.
   This program continually prompts the user.
*/

int main(int argc, char * argv[])
{
  int shouldSort,numToSort,i,sortChoice,hold,*nums; /* Declaration */
  shouldSort = 0; /* Initialization */
  numToSort = 0; /* Initialization */
  sortChoice = 0; /* Initialization */
  do
  {
    printf("Would you like to sort integers?\n");
    printf("\n     1     Yes\n");
    printf("     2     No\n");
    printf("\nEnter 1 or 2: ");
    scanf("%d",&shouldSort); /* User input */

    switch(shouldSort)
    {
        case 1 :

        do
        {
            printf("\nEnter the number of integers: ");
            scanf("%d",&numToSort); /* User input */
            if(numToSort <= 0)
            {
                printf("Invalid amount, try again.\n");
            }
        }while(numToSort <= 0);

        printf("Enter your %d integers: ",numToSort);
        nums = malloc(sizeof(int) * numToSort); /* Dynamically allocate an array of user imput length */

        for(i = 0; i < numToSort; i++) /* Puts "n" user inputed numbers into an array */
        {
            scanf("%d",&hold); /* User input */
            nums[i] = hold;
            printf("nums[%d]: %d\n",i,nums[i]);
        }


        printf("\nWhich algorithm would you like to use?\n\n");
        printf("     1     Bubble Sort\n");
        printf("     2     Selection Sort\n");
        printf("     3     Merge Sort\n");
        printf("     4     Quick Sort\n");
        printf("\n\n");

        printf("Enter 1, 2, 3, or 4: ");
        scanf("%d",&sortChoice); /* User input */
        switch(sortChoice) /* Different sorting algorithms */
        {
            case 1 :
			bubble_sort((byte *)nums,numToSort,sizeof(int),p_cmp_f);

            break;
            case 2 :
			selection_sort((byte *)nums,numToSort,sizeof(int),p_cmp_f);

            break;
            case 3 :
            merge_sort((byte *)nums,numToSort,sizeof(int),p_cmp_f);

            break;
            case 4 :
            quick_sort((byte *)nums,numToSort,sizeof(int),p_cmp_f);

            break;

            default:
                printf("Invalid choice. Retry.");
        }

        printf("Sorted Integers: ");
            for(i = 0;i < numToSort;i++)
            {
                    printf("%d ",nums[i]);
            }
            printf("\n\n");
			 free(nums);

        break;
        case 2 :
        printf("Thank you for using the system\n");

        break;

        default :
            printf("\nInvalid choice.\n");
            printf("\n");
    }
  }while(shouldSort != 2);


    return 0;
}

/*
   Function p_cmp_f compares two integers.
   Input arguments: element1 and element2 (two
   pointers to byte).
   Output:
      - A positive integer, if the first integer
        pointed to by element1 is greater than the
        second element pointed to by element2.
      - A negative integer, if the first integer
	    pointed to by element1 is less than the
	    second element pointed to by element2.
	  - Zero, if the first integer pointed to by
	    element1 is equal to the second integer
	    pointed to by element2.
*/

int p_cmp_f(byte *element1, byte *element2)
{
	return *((int *)element1) - *((int *)element2);
}
