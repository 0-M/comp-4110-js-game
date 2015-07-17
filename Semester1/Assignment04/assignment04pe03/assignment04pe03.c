/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment04pe03: Sine Function        */
/*                                                */
/* Approximate completion time: 10                 */
/**************************************************/

/*
   This program reads an integer from the command line and prints out the trigonometric sine value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
  double num,siNum; /* declaration */
  num = atof(argv[1]); /* assignment */
  siNum = sin(num); /* assignment */
  printf("The sine of %f is: %f\n",num,siNum); /* Printing sin */
  return 0;
}
