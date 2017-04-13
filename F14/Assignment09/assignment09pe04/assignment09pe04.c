/*****************************************************/
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program assignment09pe04: Recursive Digit Sum     */
/*                                                   */
/* Approximate completion time: 5                    */
/*****************************************************/

/*
   This program reads in integers and calculates the sum of it's digits, recursively.
*/

#include <stdio.h>

int digitsum(int num); /* Forward Declaration */

int main(int argc, char *argv[])
{
  int toSum; /* Declaration */
  FILE *fin; /* Pointer to a file */

  fin = fopen("testdata4", "r"); /* Opens the file */

  while( fscanf(fin, "%d", &toSum) != EOF) /* While there are values in the file */
  {
      printf("Number: %d\n Digit sum: %d\n",toSum,digitsum(toSum)); /* Sum the digits */
  }


  fclose(fin); /* Close the file */
  return 0;
}


int digitsum(int num)
{
    int sum;
    sum = 0;
if(num % 10 == 0) /* If there are no digits left */
{
    printf("base\n");
      return 0;
}
  else /* Add the digit to the sum */
  {
    sum = sum + (num % 10); /* Get's the last digit */
    num = num/10; /* Divide by 10 so that you cut off the current last digit */
    return sum + digitsum(num); /* Call digit sum on the new num which has now had one digit cut off */
  }
}
