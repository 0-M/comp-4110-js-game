#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueuePtr initQueue(); //Initialize the queue
void destroyQueue(QueuePtr que); //Destroy the queue
void enqueue(QueuePtr que,Data d); //Add the the end(tail)
Data dequeue(QueuePtr que); //Remove from the start(head)
int isEmpty(QueuePtr que); //Checks if the queue is empty or not
void emptyQueue(QueuePtr que); //Empties the queue
Data getFront(QueuePtr que); //Returns the data at the front of the queue(head)
int getSize(QueuePtr que); //Returns the size of the queue


QueuePtr initQueue() //Initialize the queue
{
    QueuePtr qp = (QueuePtr)malloc(sizeof(Queue));
    qp -> head = NULL;
    qp -> tail = NULL;
    qp -> sizeQue = 0;
    return qp;
}

void destroyQueue(QueuePtr que) //Destroy the queue
{
    if(isEmpty(que))
    {
        free(que);
    }
    else
    {
        emptyQueue(que);
        free(que);
    }

    printf("The queue has been destroyed.\n");
}

void enqueue(QueuePtr que,Data d) //Add the the end(tail)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np -> data = d;
    np -> next = NULL;
    if(isEmpty(que))
    {
        que -> head = np;
        que -> tail = np;
    }
    else
    {
        que -> tail -> next = np;
        que -> tail = np;

    }
    que -> sizeQue = que -> sizeQue + 1;
      printf("Added %d to the queue.\n",d);
}

Data dequeue(QueuePtr que) //Remove from the start(head)
{
    if(isEmpty(que))
    {
        printf("Unable to remove, the queue is empty.\n");
        return -1;
    }
    Data hold = que -> head -> data;
    NodePtr temp = que -> head;
    que -> head = que -> head -> next;
    if(que -> head == NULL) //If the queue is now empty
    {
        que -> tail = NULL;
    }
    que -> sizeQue = que -> sizeQue -1;
    free(temp);
     printf("%d has been removed from the queue.\n",hold);
    return hold;
}

int isEmpty(QueuePtr que) //Checks if the queue is empty or not
{
    return (que -> head == NULL);
}

void emptyQueue(QueuePtr que) //Empties the queue
{
    while(que -> head != NULL)
    {
        dequeue(que);
    }
    printf("The queue has been emptied.\n");
}


Data getFront(QueuePtr que) //Returns the data at the front of the queue(head)
{
    if(!isEmpty(que))
    {
        return(que -> head -> data);
    }
    else
    {
        return -1;
    }
}

int getSize(QueuePtr que) //Returns the size of the queue
{
    return(que -> sizeQue);
}
