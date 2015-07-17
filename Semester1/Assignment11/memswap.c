/*****************************************************/
/* Programmer: S. Bassil (Fall 2014)                 */
/*                                                   */
/* Program: assignment11                             */
/*                                                   */
/* Approximate Completion Time:                      */
/*****************************************************/

/*
   This function swaps n_bytes bytes, byte by byte.
*/

#include <stdio.h>
#include "typedef.h"

void memswap(byte *data1, byte *data2, int n_bytes)
{
	byte tmp;
	while (n_bytes-- > 0) {
		tmp = *data1;
		*data1++ = *data2;
		*data2++ = tmp;
	}
}
