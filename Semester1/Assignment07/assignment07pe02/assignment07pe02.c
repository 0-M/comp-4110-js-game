/*************************************************************/
/* Programmer: Zachary Krausman                              */
/*                                                           */
/* Program assignment07pe02: Inner Product of Two Arrays     */
/*                                                           */
/* Approximate completion time: 10                           */
/*************************************************************/

/*
   This program takes two arrays of four floats and using a function,
   computes the inner product and returns it. The product will then
   be printed by main.
*/

#include <stdio.h>

float inner ( float u[], float v[], int size ); /* Forward Declaration */

int main(int argc, char *argv[])
{
  int i; /* Declaration */
  float nums1[4],nums2[4]; /* Declaration */

  printf("Please enter the first four numbers: ");

  for(i = 0; i < 4; i++) /* Gets the first set of four numbers */
    scanf("%f",&nums1[i]);

  printf("Please enter the second four numbers: ");

  for(i = 0; i < 4; i++) /* Gets the second set of four numbers */
    scanf("%f",&nums2[i]);

  printf("%f",inner(nums1,nums2,4)); /* Makes a call to function inner, which returns the inner product of two arrays */

  return 0;
}

float inner ( float u[], float v[], int size ) /* Defining the function */
{
   int i; /* Declaration */
   float sum; /* Declaration */

   sum = 0; /* Initialization */
   for(i = 0; i <= size-1; i++) /* Does the inner product */
    sum = sum + (u[i] * v[i]);

   return sum; /* Returns the inner product to main */
}
