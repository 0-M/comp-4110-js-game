/**************************************************/
/* Programmer: Zachary Krausman                   */
/*                                                */
/* Program assignment0xpe0y: ProgramName          */
/*                                                */
/* Approximate completion time: ... minutes       */
/**************************************************/

/*
   This program... (description of what the program does)
*/


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char *argv[])

{

 LinkedListPtr list = initLinkedList(); //Creates a linked list
 Data checkDat;
 checkDat = 0;

 //insertAtHead(list,5);
 //insertAtHead(list,4);
 //insertAtHead(list,3);
 //insertAtHead(list,2);
 //insertAtHead(list,1);


add(list,1,0);
add(list,2,1);
add(list,3,2);
add(list,4,3);
add(list,5,4);
add(list,20,2);



 display(list);
checkDat = check(list,3);
printf("The data at position 3 is: %d\n",checkDat);
replaceData(list,3,74);
display(list);

removeData(list,1);



display(list);
emptyList(list);
display(list);
destroy(list);








    return 0;
}
