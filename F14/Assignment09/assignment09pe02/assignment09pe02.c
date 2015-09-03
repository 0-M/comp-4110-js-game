/******************************************************/
/* Programmer: Zachary Krausman                       */
/*                                                    */
/* Program assignment09pe02: Recursive Fibonacci      */
/*                                                    */
/* Approximate completion time: 20                    */
/******************************************************/

/*
   This program calculates a Fibonacci number based on user input.
*/

#include <stdio.h>

int fibonacci(int n); /* Forward declaration */

int main(int argc, char *argv[])
{
    int choice,n; /* Definition */
do
{
   printf("1- Calculate Fibonacci\n");
   printf("2- Exit\n");
   printf("(Enter 1 or 2)\n\n");
   scanf("%d",&choice); /* Get input */

   switch(choice) /* Menu */
   {
        case 1 :
            printf("Enter n: ");
            do
                {
                    scanf("%d",&n); /* Get n */
            if(n < 1)
                printf("n should be a positive integer. Retry\nEnter n: ");
                } while(n < 1);
            printf("\n");
            printf("fibonacci(%d) = %d\n\n",n,fibonacci(n)); /* Call to fibonacci */
            break;

        case 2 : /* Exit case */
            printf("Thank you!");
            break;
        default:
            printf("Invalid choice. Retry.\n\n");
   }
} while(choice != 2);
  return 0;
}


int fibonacci(int n)
{
  if(n == 0) /* n will only be 0 when n = 2 and therefore n-2 will equal 0, base case */
    return 0;
  else if(n == 1) /* n will only be 1 when n = 2 and therefore n-1 will equal 1,base case #2 */
    return 1;
  else
    return (fibonacci(n-1) + fibonacci(n-2)); /* Will keep returning until it hits the two base cases */
}
