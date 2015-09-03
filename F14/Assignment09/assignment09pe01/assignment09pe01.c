/******************************************************/
/* Programmer: Zachary Krausman                       */
/*                                                    */
/* Program assignment09pe01: Non-recursive Fibonacci  */
/*                                                    */
/* Approximate completion time: 30                    */
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
    int fib1,fib2,i; /* Declaration */
    fib1 = 1; /* Initialization */
    fib2 = 1; /* Initialization */
        for(i = 2;i < n;i++)
          {
            if(n > 2)
            {
            fib1 = fib1 + fib2; /* New value = the previous two */
            printf("f1: %d f2: %d\n",fib1,fib2);
            fib2 = fib1 - fib2; /* Set the second value to the old first value */
            }
          }
    return fib1; /* Return when done */
}
