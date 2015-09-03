/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment06pe02: scanf Returns What?  */
/*                                                */
/* Approximate completion time: 20 minutes        */
/**************************************************/

/*
   This program uses a while loop to read an unknown amount of numbers from a file then print them onto the screen
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
  int num; /* Declartation */

  FILE *fin; /* Pointer to a file */

  fin = fopen("testdata2", "r"); /* Opens the file */

  num = 0; /* Initialization */
  while( fscanf(fin, "%d", &num) != EOF) /* loop through the file and stop when there are no more characters */
  {
      printf("%d ",num); /* prints the number */
  }


  fclose(fin); /* closes the file */

  return 0;
}
