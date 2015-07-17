/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment06pe01: Area of a Circle     */
/*                                                */
/* Approximate completion time: 10 minutes        */
/**************************************************/

/*
   This program calculates the area of a circle given a radius
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 float area,radius; /* declaration */

 printf("Enter a radius: \n");

 scanf("%f",&radius); /* initialization */

 area = M_PI * (radius * radius); /* Initialization(calculate the area) */

 printf("The area of a circle with radius %f is: %f\n",radius,area); /* print the result */

  return 0;
}
