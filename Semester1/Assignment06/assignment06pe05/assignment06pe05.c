/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment06pe05: Reverse              */
/*                                                */
/* Approximate completion time: 20 minutes        */
/**************************************************/

/*
   This program reads in 10 integer numbers from the keyboard, then prints them out in reverse order.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
    int num[10],i,j; /* Declaration */

    printf("Please type in ten integers: "); /* Print statement for user */

        for(i = 0; i < 10; i++)
        scanf("%d",&num[i]); /* Get input from user */

    printf("Reversed: "); /* Print statement for user */

    for(j = 9; j >= 0; j--) /* Prints the array out in reverse order */
        printf("%d ",num[j]);




  return 0;
}
