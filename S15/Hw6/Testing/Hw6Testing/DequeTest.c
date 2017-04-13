
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Deque.h"


int main(int argc, char *argv[])
{
    int i;
    srand ( time(NULL) );
    DequePtr deque = initDeque();

    printf("Adding five random numbers at the front(head) of the deque.\n");
    printf("\n");
    addFront(deque,rand() % 100);
    addFront(deque,rand() % 100);
    addFront(deque,rand() % 100);
    addFront(deque,rand() % 100);
    addFront(deque,rand() % 100);

    printf("next: %d\n",deque -> head -> next -> data);

//     printf("\n");
//
//    printf("Checking if the queue is empty.\n");
//    if(isEmpty(deque))
//    {
//        printf("The deque is empty.\n");
//    }
//    else
//    {
//        printf("The deque is not empty.\n");
//    }
//
//     printf("\n");
//
//    printf("Getting the front element of the deque then removing it.\n");
//    for(i = 0; i < 5; i++)
//    {
//        printf("The front element is: %d.\n",getFront(deque));
//        printf("The front element %d has been removed.\n",removeFront(deque));
//    }
//
//     printf("\n");
//
//    printf("Checking if the queue is empty.\n");
//    if(isEmpty(deque))
//    {
//        printf("The deque is empty.\n");
//    }
//    else
//    {
//        printf("The deque is not empty.\n");
//    }
//
//    printf("\n\n\n");
//
//    printf("Adding five random numbers at the back(tail) of the deque.\n");
//    printf("\n");
//    addBack(deque,rand() % 100);
//    addBack(deque,rand() % 100);
//    addBack(deque,rand() % 100);
//    addBack(deque,rand() % 100);
//    addBack(deque,rand() % 100);
//
//printf("\n");
//    printf("Getting the back element of the deque then removing it.\n");
//    for(i = 0; i < 5; i++)
//    {
//        printf("The back element is: %d.\n",getBack(deque));
//        printf("The back element %d has been removed.\n",removeBack(deque));
//    }
//    printf("Checking if the queue is empty.\n");
//    printf("\n");
//    if(isEmpty(deque))
//    {
//        printf("The deque is empty.\n");
//    }
//    else
//    {
//        printf("The deque is not empty.\n");
//    }
//
//    printf("Destroying the deque.\n");
//    destroyDeque(deque);





    return 0;
}
