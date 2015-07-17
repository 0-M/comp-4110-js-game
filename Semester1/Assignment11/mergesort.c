/*****************************************************/
/* Programmer: S. Bassil (Fall 2014)                 */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   This program sorts an array of elements using the
   mergesort algorithm.
*/

#include <stdlib.h>
#include <string.h>
#include "typedef.h"

/* Utility for merge_sort() */
static void merge(byte *array1, int size1, byte *array2, int size2, byte *p_result, int (*p_cmp_f)(), int elementsize);

void merge_sort(byte data[], int size, int elementsize, int (*p_cmp_f)())
{
	byte *part1, *part2, *temp_array;
	int size1, size2;

	if (size < 0)
		return;
	if (size <= 1)
		return;

	size1 = size / 2;
	size2 = size - size1;
	part1 = data;
	part2 = data + (size1 * elementsize);

	merge_sort(part1, size1, elementsize, p_cmp_f);
	merge_sort(part2, size2, elementsize, p_cmp_f);

	temp_array = (byte *) malloc(size*elementsize);
	if (temp_array == NULL)
		return;

	merge(part1, size1, part2, size2, temp_array, p_cmp_f, elementsize);
	memcpy(data, temp_array, size*elementsize);

	free(temp_array);
}

static void merge(byte *array1, int size1, byte *array2, int size2, byte *p_result, int (*p_cmp_f)(), int elementsize)
{
	byte *p_end1 = array1 + (size1 * elementsize);
	byte *p_end2 = array2 + (size2 * elementsize);

	while ((array1 < p_end1) && (array2 < p_end2)) {
		if ((*p_cmp_f)(array1, array2) < 0) {
			memcpy(p_result, array1, elementsize);
			array1 += elementsize;
		} else {
			memcpy(p_result, array2, elementsize);
			array2 += elementsize;
		}
		p_result += elementsize;
	}
	while (array1 < p_end1) {
		memcpy(p_result, array1, elementsize);
		array1   += elementsize;
		p_result += elementsize;
	}
	while (array2 < p_end2) {
		memcpy(p_result, array2, elementsize);
		array2   += elementsize;
		p_result += elementsize;
	}
}
