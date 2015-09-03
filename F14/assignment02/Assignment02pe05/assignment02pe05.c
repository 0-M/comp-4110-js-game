/**************************************************************/
/* Programmer: Zachary Krausman                               */
/*                                                            */
/* Program assignment02pe05: One Horizontal Line of Asterisks */
/*                                                            */
/* Approximate completion time: 10                            */
/**************************************************************/



#include <stdio.h>


int main(int argc, char *argv[])
{
    int num,i;
    FILE *fin;
    fin = fopen("testdata5","r");
    fscanf(fin,"%d",&num);

    for(i = 0;i < num;i++)
        printf("*");

    printf("\n");
    fclose(fin);
    return 0;
}

