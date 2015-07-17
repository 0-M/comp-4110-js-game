/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment02pe02: Bigger than 100?     */
/*                                                */
/* Approximate completion time: 5                 */
/**************************************************/



#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    printf("Please type an integer: ");
    scanf("%d",&num);

    if (num > 100)
        printf("The number is bigger than 100.\n");
    else
        printf("The number is not bigger than 100.\n");


    return 0;
}


