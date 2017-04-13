/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment04pe02: argc                 */
/*                                                */
/* Approximate completion time: 5                 */
/**************************************************/

/*
   This program prints the number of arguments entered in the command line
*/


#include <stdio.h>


int main(int argc, char *argv[])
{

    printf("You typed %d arguments\n",argc); /* Prints the number of arguments */
    return 0;

}

