/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment03pe01: Sum of Twenty        */
/*                                                */
/* Approximate completion time: 10 minutes        */
/**************************************************/

/*
   This program reads 20 positive integer values from a file.  Adds them all together then prints this sum.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  int sum,curr,count;
  FILE *fin;
  sum = 0;
  count = 0;
  fin = fopen("testdata1", "r");
  while( fscanf(fin,"%d",&curr) != EOF && count < 20)
  {
      printf("%d\n",curr);
    sum = sum + curr;
    count = count + 1;
  }
    printf("%d  ",count);
    printf("%d",sum);


  fclose(fin);
  return 0;
}
