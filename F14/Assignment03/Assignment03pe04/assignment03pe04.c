/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment03pe04: Count Characters     */
/*                                                */
/* Approximate completion time: TBD               */
/**************************************************/

/*
   This program counts the number of characters entered from the keyboard until it recieves EOF(end of file).
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    int c;
    printf("Type characters here: ");
    num = 0;
    while((c = getchar()) !=  26 && c != 4 && c != EOF )
    {
        printf("%d  ",c);
        num = num + 1;

    }

printf("You typed %d characters.",num);


  return 0;
}
