/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment01pe05: Sum of Two Values    */
/*                                                */
/* Approximate completion time: 10 minutes         */
/**************************************************/

/*
   This program... (description of what the program does)
*/

#include <stdio.h>
/*
   More include statements should appear here.
*/

/*
   Functions declarations should appear here.
*/

int main(int argc, char *argv[])
{
  /*
     Variables declarations should appear here.
  */
  int x;
  int y;
  int sum;


    printf("Please enter two integers separated by a space: ");
    scanf("%d %d",&x,&y);
    sum = x + y;
    printf("The sum of your two integers is: %d",sum);
  /*
     Program instructions should appear here.
  */

  return 0;
}

/*
   Functions definitions should appear here.
*/

