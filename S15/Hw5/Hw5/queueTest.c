#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    int emptyCheck;
    srand ( time(NULL) );
    QueuePtr queue = initQueue(); //initialize queue
    emptyCheck = isEmpty(queue); // check if empty
    if(emptyCheck)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    enqueue(queue,rand() % 100);
    enqueue(queue,rand() % 100);
    enqueue(queue,rand() % 100);
    enqueue(queue,rand() % 100);

    emptyCheck = isEmpty(queue); // check if empty
    if(emptyCheck)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    printf("The front of the queue is: %d.\n",getFront(queue));


    dequeue(queue);
    dequeue(queue);


    printf("The size of the queue is %d.\n",getSize(queue));


    emptyQueue(queue);

    emptyCheck = isEmpty(queue); // check if empty
    if(emptyCheck)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }


    printf("The size of the queue is %d.\n",getSize(queue));

    destroyQueue(queue);



    return 0;
}
