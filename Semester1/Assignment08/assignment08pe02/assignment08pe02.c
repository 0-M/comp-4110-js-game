/*******************************************************************/
/* Programmer: Zachary Krausman                                    */
/*                                                                 */
/* Program assignment08pe02: Simulating Call by Reference          */
/*                                                                 */
/* Approximate completion time: 5                                  */
/*******************************************************************/

/*
   This program reads in two integer values and swaps them.
*/

#include <stdio.h>


void swap(int *int1,int *int2); /* Forward Declaration */

int main(int argc, char *argv[])
{
    int num1, num2; /* Declaration */

    printf("Enter the first integer: ");
    scanf("%d",&num1); /* Gets the first number */

    printf("Enter the second integer: ");
    scanf("%d",&num2); /* Gets the second number */

    swap(&num1,&num2); /* Calls the swap function */

    printf("First: %d\nSecond: %d",num1,num2); /* Prints the result */


  return 0;
}


void swap(int *int1,int *int2)
{
    int temp; /* Declaration */

    temp = *int1; /* Hold the value of the first integer */

    *int1 = *int2; /* Assign the value of the first integer to be equal to the second */

    *int2 = temp;  /* Assign the value of the second integer to be equal to the held value(the first integer) */

}
