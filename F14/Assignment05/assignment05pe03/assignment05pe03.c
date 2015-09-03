/*****************************************************/
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program assignment05pe03: One Dimensional Array   */
/*                                                   */
/* Approximate completion time: 10 minutes           */
/*****************************************************/

/*
   This program reads 15 integer values and puts then into an array and prints the numbers from the array in reverse order.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{

  int nums[15],i,z; /* Declaration */
  FILE *fin;
  fin = fopen("testdata3","r");

  for(i = 0;i < 15;i++)  /* Puts the characters from the file into the array */
  {
     fscanf(fin,"%d",&nums[i]);
  }


  for(z = 14;z >= 0;z--)
  {
   printf("%d\n",nums[z]); /* Prints the array in reverse order */
  }

  return 0;
}
