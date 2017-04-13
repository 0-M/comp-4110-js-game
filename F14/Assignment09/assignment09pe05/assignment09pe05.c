/*******************************************************************/
/* Programmer: Zachary Krausman                                    */
/*                                                                 */
/* Program assignment09pe05: Non-recursive Persistence of a Number */
/*                                                                 */
/* Approximate completion time: ... minutes                        */
/*******************************************************************/

/*
   This program calculates the persistence number of an integer iteratively.
*/

#include <stdio.h>

int persistence(int num);

int main(int argc, char *argv[])
{
  int num,c; /* Declaration */
  do
  {
    printf("Enter a number: ");
    c = scanf("%d",&num); /* To check for EOF */
    if(c != EOF)
    {
          printf("The persistence number of %d is %d\n",num,persistence(num));
    }
  }while (c != EOF);



  return 0;
}



int persistence(int num)
{
int prod,pnum; /* Declaration */
  pnum = 0; /* Initialization */
while(num - 10 > 0)
{
      prod = 1; /* product of integers */
      pnum = pnum + 1; /* Persistence number count */
  while(num % 10 != 0)
  {
     prod = prod * (num % 10); /* Get's the last digit */
     num = num/10; /* Divide by 10 so that you cut off the current last digit */
  }
  num = prod;
  printf("prod: %d\n",prod);
}


  return pnum;
}
