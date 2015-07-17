/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment08pe01: Unfilled Box         */
/*                                                */
/* Approximate completion time: 10                */
/**************************************************/

/*
   This program accepts a user input length and height and prints out an asterisk box.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
    int l,h,i,z; /* Declaration */

    printf("Enter in a length: ");
    scanf("%d",&l);  /* Get the length */

    printf("Enter in a height: ");
    scanf("%d",&h); /* Get the height */


    printf("\n"); /* Start the box on a new line */

    for(i  = 0; i < h;i++) /* Loop height times */
    {
        for(z = 0; z < l;z++) /* Loop length times */
        {
          if(i == 0 || i == h - 1 || z == 0 || z == l - 1) /* If it's the first or last row or first or last in a column */
            printf("*");
          else
            printf(" ");


          if(z == l - 1) /* Go to next row */
            printf("\n");
        }
    }


  return 0;
}
