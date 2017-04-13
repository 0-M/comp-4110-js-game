/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment06pe03: Sum of a Bunch       */
/*                                                */
/* Approximate completion time: 5 minutes         */
/**************************************************/

/*
   This program reads numbers from a file and sums them together without using an array
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
  int num,sum; /* Declartation */

  FILE *fin; /* Pointer to a file */

  fin = fopen("testdata3", "r"); /* Opens the file */

  sum = 0;
  num = 0; /* Initialization */
  while( fscanf(fin, "%d", &num) != EOF) /* loop through the file and stop when there are no more characters */
  {
      sum = sum + num;  /* adds the number */
  }

  printf("Sum: %d\n",sum);

  fclose(fin); /* closes the file */


  return 0;
}
