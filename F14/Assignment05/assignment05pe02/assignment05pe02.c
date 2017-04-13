/*******************************************************/
/* Programmer: Zachary Krausman                        */
/*                                                     */
/* Program assignment05pe02: Reverse the Command Line  */
/*                                                     */
/* Approximate completion time: 10 minutes             */
/*******************************************************/

/*
   This program prints out the command line arguments in reverse order
*/

#include <stdio.h>


int main(int argc, char *argv[])
{

 int i; /* Declaration */

 for(i = argc;i >= 1;i--)  /* Counts down */
    printf("%s\n",argv[i-1]); /* Prints out the command line argument, has a -1 to offset the 0 based system */

  return 0;
}
