/******************************************************************/
/* Programmer: Zachary Krausman                                   */
/*                                                                */
/* Program assignment03pe02: Positive,Negative, or Zero?          */
/*                                                                */
/* Approximate completion time: 5 minutes                         */
/******************************************************************/

/*
   This program gets one integer from the keyboard and determines whether it is positive negative or zero.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{

    int num;
    printf("Please enter an integer: ");
    scanf("%d",&num);

    if(num > 0)
        printf("The number is positive.");
    else if (num < 0)
        printf("The number is negative.");
    else
        printf("The number is zero.");
  return 0;
}
