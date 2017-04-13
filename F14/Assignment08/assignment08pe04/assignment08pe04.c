/*****************************************************/
/* Programmer: Zachary Krausman                      */
/*                                                   */
/* Program assignment08pe04: Simply Two Dimensional  */
/*                                                   */
/* Approximate completion time: ... minutes          */
/*****************************************************/

/*
   This program allocates memory for an array of pointers, each pointer points to a float in another array.  Averages the rows and columns.
*/

#include <stdio.h>
#include <stdlib.h>

int r = 3;
int c = 5;


int main(int argc, char *argv[])
{
 int i,j;
 float **nums1,sumRow[3],sumCol[5];
 FILE *fin;

 fin = fopen("testdata4","r");

 nums1 = (float **) malloc(r * sizeof(float *));

 for(i = 0;i < r;i++)
 {
     nums1[i] = (float *) malloc(c * sizeof(float));

 }

 for(i = 0; i < r;i++)
 {
     for(j = 0; j < c;j++)
     {
        fscanf(fin,"%f",&nums1[i][j]);
     }

 }

 for(i = 0;i < r;i++)
    {
        for(j = 0;j < c;j++)
        {
            sumRow[i] = sumRow[i] + nums1[i][j];
        }
        sumRow[i] = sumRow[i]/c;
    }
sumCol[4] = 0;
 for(i = 0;i < c;i++)
    {
        for(j = 0;j < r;j++)
        {
            sumCol[i] = sumCol[i] + nums1[j][i];
        }
        sumCol[i] = sumCol[i]/r;
    }

  fclose(fin);
  free(nums1);
  free(nums1[0]);
  free(nums1[1]);
  free(nums1[2]);
  printf("The average values for the three rows are: %.2f  %.2f  %.2f\n",sumRow[0],sumRow[1],sumRow[2]);
  printf("The average values for the five columns are: %.2f  %.2f  %.2f  %.2f  %.2f",sumCol[0],sumCol[1],sumCol[2],sumCol[3],sumCol[4]);

  return 0;
}
