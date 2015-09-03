/*****************************************************/
/* Programmer: S. Bassil (Fall 2014)                 */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   Declaration of functions bubble_sort, selection_sort,
   merge_sort, and quick_sort.
*/

#include "typedef.h"

void bubble_sort(byte data[], int size, int elementsize, int (*p_cmp_f)());
void selection_sort(byte data[], int size, int elementsize, int (*p_cmp_f)());
void merge_sort(byte data[], int size, int elementsize, int (*p_cmp_f)());
void quick_sort(byte data[], int size, int elementsize, int (*p_cmp_f)());