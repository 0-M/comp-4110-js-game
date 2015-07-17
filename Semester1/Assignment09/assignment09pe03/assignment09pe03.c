/*****************************************************/
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program assignment09pe04: Non-recursive Digit Sum */
/*                                                   */
/* Approximate completion time: ... minutes          */
/*****************************************************/

/*
   This program reads in integers and calculates the sum of it's digits.
*/

#include <stdio.h>

int digitsum(int num); /* Forward Declaration */

int main(int argc, char *argv[])
{
  int toSum; /* Declaration */
  FILE *fin; /* Pointer to a file */

  fin = fopen(argv[1], "r"); /* Opens the file */

  while( fscanf(fin, "%d", &toSum) != EOF) /* While there are values in the file */
  {
      printf("Number: %d\n Digit sum: %d\n",toSum,digitsum(toSum)); /* Sum the digits */
  }


  fclose(fin); /* Close the file */
  return 0;
}


int digitsum(int num)
{
  int sum; /* Declaration */
  sum = 0; /* Initialization */
  while(num % 10 != 0)
  {
     sum = sum + (num % 10); /* Get's the last digit */
     num = num/10; /* Divide by 10 so that you cut off the current last digit */
  }
  return sum;
}
