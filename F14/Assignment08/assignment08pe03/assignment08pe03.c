/****************************************************************/
/* Programmer: Zachary Krausman                                 */
/*                                                              */
/* Program assignment08pe03: Malloc up a Two-Dimensional Array  */
/*                                                              */
/* Approximate completion time: ... minutes                     */
/****************************************************************/

/*
   This program prints out the sum of all the values in a two dimensional array
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int r,c,*nums,i,j,sum; /* Declaration */

  printf("Enter the number of rows: ");
  scanf("%d",&r); /* Get the rows */

  printf("Enter a number of columns: ");
  scanf("%d",&c); /* Get the colums */

  nums = (int *) malloc(r * c * sizeof(int)); /* Allocate space for the array */

  for(i = 0;i < r;i++) /* Assign a value to each space in the array */
  {
      for(j = 0;j < c;j++)
      {
        nums[i * c + j] = (i + j);
      }

  }

  sum = 0; /* Initialization */
  for(i = 0;i < r * c;i++) /* Sum the array */
    sum = sum + nums[i];

  printf("Sum: %d",sum); /* Print the sum */

  free(nums); /* Free the memory */

  return 0;
}
