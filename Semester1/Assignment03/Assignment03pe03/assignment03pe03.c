/*****************************************************/
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program assignment03pe03: Using the sqrt Function */
/*                                                   */
/* Approximate completion time: 5 minutes            */
/*****************************************************/

/*
   This program will accept a float from a user and will then print out the square root of that number
*/

#include <stdio.h>
#include <math.h>



int main(int argc, char *argv[])
{
  float num;
  printf("Please enter a floating point number: ");
  scanf("%f",&num);
  printf("The square root of your number is: %f", sqrt(num));


  return 0;
}
