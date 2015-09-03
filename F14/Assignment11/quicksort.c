/*****************************************************/
/* Programmer: S. Bassil (Fall 2014)                 */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   This function sorts an array of elements using the
   quicksort algorithm.
*/

#include "memswap.h"

#define ELEMENTS_BETWEEN(p_left, p_right) (((p_right) - (p_left)) / elementsize)
#define GOTO_NEXT_ELEMENT(p_elt) ((p_elt) += elementsize)
#define GOTO_PREV_ELEMENT(p_elt) ((p_elt) -= elementsize)

/* Utilities for quick_sort() */
static byte *partition (byte data[], int size, int elementsize, int (*p_cmp_f)());
static byte *select_pivot(byte data[], int size, int elementsize, int (*p_cmp_f)());

void quick_sort(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	byte *p_right;
	int   leftsize;

	if (size <= 1) return;
	p_right = partition(data, size, elementsize, p_cmp_f);
	leftsize = ELEMENTS_BETWEEN(data, p_right);
	quick_sort(data, leftsize, elementsize, p_cmp_f);
	quick_sort(p_right, size - leftsize, elementsize, p_cmp_f);
	return;
}

static byte *partition(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	byte *p_left, *p_right, *p_pivot;

	p_left  = data;
	p_right = data + (size - 1) * elementsize;

	p_pivot = select_pivot(data, size, elementsize, p_cmp_f);
	memswap(p_pivot, p_right, elementsize);
	p_pivot = p_right;
	while (p_left < p_right) {
		   while ((*p_cmp_f)(p_left, p_pivot) < 0 && p_left < p_right)
			GOTO_NEXT_ELEMENT(p_left);
		   while ((*p_cmp_f)(p_right, p_pivot) >= 0 && p_left < p_right)
			GOTO_PREV_ELEMENT(p_right);
		   if (p_left < p_right) {
			memswap(p_left, p_right, elementsize);
			GOTO_NEXT_ELEMENT(p_left);
		   }
	}
	if (p_right == data) {
		memswap(p_right, p_pivot, elementsize);
		GOTO_NEXT_ELEMENT(p_right);
	}
	return p_right;
}

static byte *select_pivot(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	return data;
}
