/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment02pe01: The fscanf Function  */
/*                                                */
/* Approximate completion time: 15                */
/**************************************************/



#include <stdio.h>


int main(int argc, char *argv[])
{
    int num;
    FILE *fin;
    fin = fopen("testdata1","r");
    fscanf(fin,"%d",&num);
    printf("%d",num);
    fclose(fin);

    return 0;
}

