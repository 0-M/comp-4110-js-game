/*******************************************************************/
/* Programmer: Zachary Krausman                                    */
/*                                                                 */
/* Program assignment09pe06: Recursive Persistence of a Number     */
/*                                                                 */
/* Approximate completion time: ... minutes                        */
/*******************************************************************/


/*
   This program calculates the persistence number of an integer recursively.
*/

#include <stdio.h>

int check = 0;

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
int prod; /* Declaration */
  prod = 1;
if (check == 0)
{
  check = 1;
}

if(num - 10 <= 0)
 {
     return 0; /* Base Case */
 }
 else
 {
     while(num % 10 != 0)
  {
     prod = prod * (num % 10); /* Get's the last digit */
     num = num/10; /* Divide by 10 so that you cut off the current last digit */
  }
  num = prod;
  return persistence(num) + 1; /* Recursion, when it hits the base case it'll count up by one
                                the amount of times the function has been called which is
                                the same as making a counter  */
 }



}

