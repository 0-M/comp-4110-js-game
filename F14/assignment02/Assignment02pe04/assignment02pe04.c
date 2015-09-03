/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment02pe04: Using a For Loop     */
/*                                                */
/* Approximate completion time: 15                */
/**************************************************/



#include <stdio.h>


int main(int argc, char *argv[])
{
    int currNum,i;
    FILE *fin;
    fin = fopen("testdata4","r");

    for (i = 0;i <= 4;i++)
    {
        fscanf(fin,"%d",&currNum);
        printf("%d ",currNum);

    }

    fclose(fin);

    return 0;
}

