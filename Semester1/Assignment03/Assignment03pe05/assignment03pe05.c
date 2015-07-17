/****************************************************/
/* Programmer: Zachary Krausman                     */
/*                                                  */
/* Program assignment03pe05: Solid Box of Asterisks */
/*                                                  */
/* Approximate completion time: ... minutes         */
/****************************************************/

/*
   This program... (description of what the program does)
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
    int L,H,i,j;
    L = 0;
    H = 0;

    printf("Please enter a positive length that is less than 21: ");
    scanf("%d",&L);
    while(L > 21 || L < 0)
    {
        printf("You did not enter a valid length, please enter another length: ");
        scanf("%d",&L);
    }

    printf("Please enter a positive height that is less than 21: ");
    scanf("%d",&H);
    while(H > 21 || H < 0)
    {
        printf("You did not enter a valid length, please enter another length: ");
        scanf("%d",&H);
    }
    printf("\n");
    for(i = 0;i < H;i++)
    {

        for(j = 0;j < L;j++)
            printf("*");
        printf("\n");
    }








    return 0;
}
