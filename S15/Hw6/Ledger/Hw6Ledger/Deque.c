#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"



DequePtr initDeque(); //Initialize the queue
void destroyDeque(DequePtr deq); //Destroy the queue
int isEmpty(DequePtr deq); //Check is the queue is empty
void emptyDeq(DequePtr deq); //Empties the queue
Data getFront(DequePtr deq); //Returns the front element in the queue
Data getBack(DequePtr deq); //Returns the back element in the queue
void addFront(DequePtr deq,Data d); //Adds an element to the front of the queue
void addBack(DequePtr deq,Data d); //Adds an element to the back of the queue
Data removeFront(DequePtr deq); //Removes and returns the front element of the queue
Data removeBack(DequePtr deq); //Removes and returns the last element of the queue
Data removeBack(DequePtr deq); //Removes and returns the last element of the queue

DequePtr initDeque() //Initialize the queue
{
    DequePtr qp = (DequePtr)malloc(sizeof(Deque));
    qp -> head = NULL;
    qp -> tail = NULL;
    return qp;
}

void destroyDeque(DequePtr deq) //Destroy the queue
{
    if(isEmpty(deq))
    {
        free(deq);
    }
    else
    {
        emptyDeq(deq);
        free(deq);
    }

    printf("The queue has been destroyed.\n");
}


int isEmpty(DequePtr deq) //Check is the queue is empty
{
    return (deq -> head == NULL);
}

void emptyDeq(DequePtr deq) //Empties the queue
{
    while(deq -> head != NULL)
    {
        removeFront(deq);
    }
    printf("The queue has been emptied.\n");
}

Data getFront(DequePtr deq) //Returns the front element in the queue
{
    return(deq -> head -> data);
}

Data getBack(DequePtr deq) //Returns the back element in the queue
{
    return(deq -> tail -> data);
}

void addFront(DequePtr deq,Data d) //Adds an element to the front of the queue
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    NodePtr temp = deq -> head;
    np -> data = d;
    np -> next = NULL;
    np -> prev = NULL;
    if(isEmpty(deq))
    {
        deq -> head = np;
        deq -> tail = np;
    }
    else
    {
        np -> next = temp;
        deq -> head = np;
        temp -> prev = np;
    }
}

void addBack(DequePtr deq,Data d) //Adds an element to the back of the queue
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    NodePtr temp = deq -> tail;
    np -> data = d;
    np -> next = NULL;
    np -> prev = NULL;
    if(isEmpty(deq))
    {
        deq -> head = np;
        deq -> tail = np;
    }
    else
    {
        deq -> tail -> next = np;
        deq -> tail = np;
        np -> prev = temp;

    }
}

Data removeFront(DequePtr deq) //Removes and returns the front(head) element of the queue
{
    NodePtr temp = deq -> head;
    Data hold = deq -> head -> data;
    deq -> head = deq -> head -> next;
    if(deq -> head != NULL)
    {
        deq -> head -> prev = NULL;
    }
    else
    {
        deq -> head = NULL;
        deq -> tail = NULL;
    }
    return (hold);
}

Data removeBack(DequePtr deq) //Removes and returns the last(tail) element of the queue
{
    NodePtr temp = deq -> tail;
    Data hold = deq -> tail -> data;
    deq -> tail = deq -> tail -> prev;
    if(deq -> tail != NULL)
    {
        deq -> tail -> next = NULL;
    }
    else
    {
        deq -> head = NULL;
        deq -> tail = NULL;
    }
    free(temp -> data.nameOfStock);
    free(temp);
    return (hold);
}
