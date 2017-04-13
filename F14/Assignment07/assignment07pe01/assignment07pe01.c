/**************************************************************/
/* Programmer: Zachary Krausman                               */
/*                                                            */
/* Program assignment07pe01: Passing a Two-dimensional Array  */
/*                                                            */
/* Approximate completion time: ... minutes                   */
/**************************************************************/

/*
   This program takes in 12 integers from the command line and puts them into a 3 by 4 array
    and using a funtion "sum" will sum the values and return this and will then
     be printed
*/

#include <stdio.h>

int sum(int arr[][4]); /* Forward Declaration */

int main(int argc, char *argv[])
{
 int nums[3][4],i,j; /* Declaration */

 printf("Enter 12 integers: ");
 for(j = 0;j < 3; j++) /* Gets the input and puts it in the two dimensional array */
 {
    for(i = 0;i < 4; i++)
        scanf("%d",&nums[j][i]);
 }
  printf("%d",sum(nums)); /* Calling the function */
  return 0;
}

int sum(int arr[][4]) /* Defining the function */
{
 int sum,i,j; /* Declaration */
 sum = 0; /* Initialization */
 for (i = 0; i < 3;i++) /* Does the sum */
  {
    for (j = 0;j < 4;j++)
      {
        sum = sum + arr[i][j];
      }

  }
    return sum; /* Returns the sum */
}
