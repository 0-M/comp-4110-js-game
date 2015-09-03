/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment06e04: fgetc and toupper     */
/*                                                */
/* Approximate completion time: 5 minutes         */
/**************************************************/

/*
   This program reads in a text file character by using fgetc.  It prints an exact copy of the file it's given except lowercase letters are converted to uppercase.
*/

#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
  char ch; /* Declaration */

  FILE *fin; /* Pointer to a file */

  fin = fopen("testdata4", "r"); /* Opens the file */

  while(fscanf(fin, "%c", &ch) != EOF)
    putchar(toupper(ch)); /* Prints the uppercase character */

  return 0;
}
