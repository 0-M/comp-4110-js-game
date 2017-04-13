#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pq.h"



int main(int argc, char *argv[])
{
    QueuePtr queue = initQueue();
    getData(queue,5);
    display(queue);
    printf("The size of the queue is %d.\n",getSize(queue));
    printf("The highest priority assignment is: \n");
    printData(getHighestPtr(queue));
    printf("\n\n");
    printf("Removing the assignment with the highest priority, that assignment is: \n");
    printData(dequeue(queue));
    printf("\n\n");
    printf("Removing the assignment with the highest priority, that assignment is: \n");
    printData(dequeue(queue));
    printf("\n\n");
    printf("The size of the queue is %d.\n",getSize(queue));
    emptyQueue(queue);
    printf("The size of the queue is %d.\n",getSize(queue));
    destroyQueue(queue);








    return 0;
}
