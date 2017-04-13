/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment04pe01: The abs Function     */
/*                                                */
/* Approximate completion time: 10                */
/**************************************************/

/*
   This program reads a string from the command line, converts to an integer and prints the absolute value of that integer.
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int num; /*declaration */
  num = atoi(argv[1]); /* assignment */
  printf("The absolute value of %d is: %d\n",num,abs(num)); /*Prints the input number and then the absolute value of that number */


  return 0;
}
