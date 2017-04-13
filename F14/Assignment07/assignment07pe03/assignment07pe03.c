/**************************************************************/
/* Programmer: Zachary Krausman                               */
/*                                                            */
/* Program assignment07pe0y: Malloc Up Space for One Integer  */
/*                                                            */
/* Approximate completion time: 5                             */
/**************************************************************/

/*
   This program mallocs space dynamically for one integer.  Puts the integer 6 into that space.  Prints the value of that space then frees the space.
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int *num; /* Declares a pointer to an integer */

  num = (int *) malloc(sizeof(int)); /* Sets the pointer equal to a specific address */

  *num = 6; /* Sets the contents of that address to be 6 */

  printf("%d",*num); /* Prints out the dereferenced value of the address, which is 6 */

  free(num); /* Frees the memory to be used elsewhere */

  return 0;
}
