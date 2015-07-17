/******************************************************************************************/
/* Programmer: Zachary Krausman                                                           */
/*                                                                                        */
/* Program assignment04pe07: Malloc Up Space for a One-Dimensional Array of n integers    */
/*                                                                                        */
/* Approximate completion time: 10 minutes                                                */
/******************************************************************************************/

/*
   This program Mallocs input for an array of user inputed length.  Then fills the array
   with user inputed values.  Then goes through the array and finds the sum and prints it out.

*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  int n,i,*arr,sum; /* Declaration */

  printf("How many integers are you going to enter? ");
  scanf("%d",&n); /* Get's an integer(size of array) */

  arr = (int *) malloc(sizeof(int)* n); /* Malloc's space for "n" number of integers */
  printf("Enter %d numbers: ",n);

  for(i = 0; i < n; i++) /* Puts "n" user inputed numbers into an array */
    scanf("%d",&arr[i]);

  sum = 0; /* Initialization */
  for(i = 0; i < n; i++) /* Sums the array */
    sum = sum + arr[i];

  printf("Sum: %d\n",sum); /* Prints the sum */

  free(arr); /* Frees the memory used by the array */

  return 0;
}
