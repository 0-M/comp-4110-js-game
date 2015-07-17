/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment04pe04: Area of a Rectangle  */
/*                                                */
/* Approximate completion time: 10                */
/**************************************************/

/*
   This program takes two inputs from the keyboard that represent the length and height of rectangle and outputs the area
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
   float l,h; /* declare */
   l = 0; /* initialize  */
   h = 0; /* initialize */
   while(l <= 0) /*Keeps asking for a float until a valid number is given */
   {
      printf("Please enter a length: ");
      scanf("%f",&l);
   }
    while(h <= 0) /* Keeps asking for a float until a valid number is given */
   {
      printf("Please enter a height: ");
      scanf("%f",&h);
   }

   printf("The area of a %f by %f rectangle is: %f\n",l,h,l * h); /* Prints out the area of the rectangle */



  return 0;
}
