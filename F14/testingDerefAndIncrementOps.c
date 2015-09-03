/* S. BASSIL */
/* FALL 2014 */

#include <stdio.h>

int main(int argc, char * argv[]){

  int table[3] = { 5, 10, 15 };
  int * array = table;

  printf("\n\n");
  printf("int table[3] = { 5, 10, 15 }\n");
  printf("int * array = table;\n\n");

  printf("*array++ = %d\n", *array++);
  /* ops * and ++ are at the same level of precedence */
  /* they both evaluate Right to Left */
  /* So, ++ is considered first, however, ++ is a post-increment. */
  /* As a consequence, array is dereferenced first */
  /* then array is incremented by 1 (array will now point to table[1]. */
  /* The value of this expression would be 5. */

  printf("*++array = %d\n", *++array);
  /* ops * and ++ are at the same level of precedence */
  /* they both evaluate Right to Left. */
  /* So, ++ is considered first, ++ is a pre-increment. */
  /* As a consequence, array is incremented by 1 (array will now point to table[2]. */
  /* Then, array is dereferenced. The value of this expression would be 15. */

  printf("++*array = %d\n", ++*array);
  /* array is dereferenced first. */
  /* So, table[2] is accessed and value 15 is incremented by 1. */
  /* The value of this expression is 16. */

  printf("(*array)++ = %d\n\n", (*array)++);
  /* array is dereferenced first. */
  /* So, table[2] is accessed and 16 would be the value of this expression. */
  /* Then, because of the post-incremented, table[2] is incremented by 1 to become 17. */

  printf("table[0] = %d\n", table[0]);
  printf("table[1] = %d\n", table[1]);
  printf("table[2] = %d\n", table[2]);

  printf("\n\n");

  return 0;
}
