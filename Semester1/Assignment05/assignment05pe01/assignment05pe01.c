/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment05pe01: Argv                 */
/*                                                */
/* Approximate completion time: 5 minutes         */
/**************************************************/

/*
   This program prints out each command line argument on a separate line.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{

 int i; /* declaration */

 for(i = 0;i <= (argc - 1);i++)
    printf("%s\n",argv[i]); /* Print out the command line argument */

  return 0;
}
