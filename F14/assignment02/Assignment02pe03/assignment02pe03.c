/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment02pe03: Equal to Zero?       */
/*                                                */
/* Approximate completion 5                       */
/**************************************************/



#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    printf("Please type an integer: ");
    scanf("%d",&num);

    if (num == 0)
        printf("The number is equal to zero.\n");
    else
        printf("The number is not equal to zero.\n");

    return 0;
}

